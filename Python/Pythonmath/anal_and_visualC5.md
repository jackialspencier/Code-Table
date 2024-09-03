# 第五章 线性规划
数学上，用来确定多变量线性函数在变量满足线性约束条件下的最优值
线性规划模型三要素：
- 决策变量：达到目标要控制的量，问题求解=找出决策变量最终取值
- 目标函数：希望优化的指标，决策变量的线性函数
- 约束条件：决策变量的限制范围

## 5.1 线性条件的概念和理论
### 1. 线性规划的一般形式
max(min) z = $\mathbf{c^{T}}$${\mathbf{x}}$
s.t.:
- $\mathbf{Ax}$ = $\mathbf{b}$
- $\mathbf{x}$ >= 0

线性规划的目标函数可以是最大化也可以是最小化函数

### 2. 线性规划解的概念和理论
线性规划模型相关定义：
- 可行解：满足全部约束条件的约束向量
- 可行域：全部可行解构成的集合
- 最优解：使目标函数达到最优值的可行解

单纯形法：在凸面体顶点中寻找最优解的迭代策略
- 基本可行解：凸面体顶点所对应的可行解
- 思路：鉴别一个基本可行解是否为最优解，若不是则按一定法则换到下一个再鉴别
- 可行性：基本可行解个数有限，可以找出最优解或判别出问题无最优解

### 3. 可转化为线性规划的问题
看起来不是线性规划的问题也可以变换转化为线性规划问题求解
- 决策变量绝对值线性组合
- 目标函数min max 或 max min的相关问题也可以线性化

## 5.2 线性规划的Python求解

### 5.2.1 用scipy.optimize模块求解
Scipy的Scipy.optimize模块提供了一个求解线性规划的函数linprog：
- 集中了求解线性规划的常用算法，如单纯形法、内点法等
- 可以根据问题的规模or用户的指定 选择算法

SciPy线性规划模型的标准型
min z = $\mathbf{c^{T}x}$
s.t.:
- $\mathbf{A·x}$ <=  $\mathbf{b}$
- $\mathbf{Aeq·x}$ = $\mathbf{beq}$
- $\mathbf{Lb}$ <= $\mathbf{x}$ <= $\mathbf{Ub}$

linprog的基本调用格式：
``` py
from scipy.optimize import linprog
res = linprog(c, A, b, Aeq, beq)    # 默认每个决策变量下界为0，上界为+∞
res = linprog(c, A=None, b=None, Aeq=None, beq=None, bounds=None, method='simplex')
print(res.fun)  # 显示目标函数最小值
print(res.x)    # 显示最优解
```

例5.1 求解线性规划问题
``` py
# 程序文件Pex5_1.py
from scipy.optimize import linprog
c = [-1, 4]
A = [[-3, 1], [1, 2]]
B = [6, 4]
bounds = ((None, None), (-3, None))

res = linprog(c, A, B, None, None, bounds)
print("目标函数的最小值为", res.fun)
print("最优解为", res.x)
```

例5.2 求解线性规划问题
``` py
#程序文件Pex5_2_1.py
from scipy.optimize import linprog

c = [-1, 2, 3]
A = [[-2, 1, 1], [3, -1, -2]]
B = [[9], [-4]]
Aeq = [[4, -2, -1]]
beq = [-6]
LB = [-10, 0, None]
UB = [None]*len(c)  #生成三个None的列表
bound = tuple(zip(LB, UB))  # 生成决策向量的元组

res = linprog(c, A, B, Aeq, beq, bound)
print("目标函数的最小值为：", res.fun)
print("最优解为：", res.x)
```
列表不可以取相反数，因此为取相反数，也可以使用数组

例5.3 
建模：
决策变量：五种原油 $x_{1}，x_{2}，x_{3}，x_{4}，x_{5}$, 成品油吨数 $x_{6}$
目标函数净利润达到最大值 $z = -110x_{1} -120x_{2} -130x_{3} -110x_{4} -115x_{5} + 150x_{6}$
约束条件：
- 精炼能力限制：植物油 $x_{1} + x_{2}$ <= 200, 非植物油 $x_{3} + x_{4} + x_{5}$ <= 250
- 硬度限制：
    - 上限：$8.8x_{1}+6.1x_{2}+2.0x_{3}+4.2x_{4}+5.0x_{5}$ <= $6x_{6}$
    - 下限：$8.8x_{1}+6.1x_{2}+2.0x_{3}+4.2x_{4}+5.0x_{5}$ >= $3x_{6}$
- 均衡性限制：$x_{1}+x_{2}+x_{3}+x_{4}+x_{5}$ = $x_{6}$
- 非负性限制：$x_{i}>=0$, i = 1, 2, ...,6

改写为对应Python库函数所需的标准形
``` py
# 程序文件Pex5_3.py
from scipy.optimize import linprog

c = [110, 120, 130, 110, 115, -150]
A = [[1, 1, 0, 0, 0, 0], [0, 0, 1, 1, 1, 0], [8.8, 6.1, 2.0, 4.2, 5.0, -6],
     [-8.8, -6.1, -2.0, -4.2, -5.0, 3]]
b = [[200], [250], [0], [0]]
Aeq = [[1, 1, 1, 1, 1, -1]]
beq = [0]

res = linprog(c, A, b, Aeq, beq)
print("目标函数最小值为：", res.fun)
print("最优解为：", res.x)
```

### 5.2.2 用cvxopt.solvers模块求解
标准型(区别于linprog，少一个限制类型，没有bounds参数)
``` 
min   z = cTx
s.t.  A·x <= b
      Aeq·x = beq
```
例5.4 求解线性规划
attention:
- 程序没有直接使用NumPy的函数，也必须加载
- 数据如果全部为整型数据，也必须(将其中至少一个)写成浮点型数据
``` py
# 程序文件5_4.py
import numpy as np
from cvxopt import matrix, solvers

c = matrix([-4., -5])
A = matrix([[2., 1], [1, 2], [-1, 0], [0, 1]]).T
b = matrix([3., 3, 0, 0])

sol = solvers.lp(c, A, b)
print("最优解为：\n", sol['x'])
print("最优值为：", sol['primal objective'])
```

例5.5 求解线性规划
``` py
# 程序文件Pex5_5.py
import numpy as np
from cvxopt import matirx,solvers

c = matrix([2., 1])
A = matrix([-1., 1], [-1, -1], [1, -2], [0, -1]).T  # 注意A矩阵需要转置，从2行4列转为(4,2)
b = matrix([1, -2, 4, 0])
Aeq = matrix([1, 2])    # Aeq为行向量
beq = matrix(3.5)   # 不需要[]列表形式

sol = solvers.lp(c, A, b, Aeq, beq)
print("目标解为：\n", sol['x'])
print("目标值为：", sol['primal objective'])
```

### 5.2.3 用cvxpy求解

## 5.3 灵敏度分析

## 5.4 投资的收益和风险