# 第6章 整数规划与非线性规划
## 6.1 整数规划
### 6.1.1 整数规划问题与求解
整数规划目前没有有效求解一切问题的方法，常见方法：
- 分支定界法：纯/混合整数线性规划
- 割平面法：纯/混合整数线性规划
- 隐枚举法：0-1整数规划（过滤隐枚举法+分支隐枚举法）
- Monte Carlo法：求解各种类型规划

cvx库求解整数规划范例
例6.1 求解整数规划问题
``` py
import cvxpy as cp
from numpy import array

c = array([40, 90])             # 定义目标向量
a = array([[9, 7], [-7, -20]])  # 定义约束矩阵
b = array([56, -70])            # 定义约束条件的右边向量
x = cp.Variable(2, integer = True)  # 定义两个整数决策变量

obj = cp.Minimize(c*x)          # 构造目标函数
cons = [a*x <= b, x >= 0]       # 构造约束条件
prob = cp.Problem(obj, cons)    # 构造问题模型
prob.solve(solver = 'GLPK_MI', verbose = True)  # 求解问题
print("最优值为: ", prob.value)
print("最优解为: \n", x.value)
```

### 6.1.2 指派问题和求解
#### 1. 标准指派问题
标准指派问题的数学模型：
min:  $\Sigma \Sigma c_{ij}x_{ij}$ 
s.t.:
- $j\Sigma x_{ij} = 1$ -----i = 1, 2, ···, n
- $i\Sigma x_{ij} = 1$ -----j = 1, 2, ···, n
- $x_{ij} = 0, 1$   -----i, j = 1, 2, 3, ···,n

例6.2 商业公司，5个新店 $B_{j}$，5个建筑公司 $A_{i}$， $A_{i}$对$B_{j}$ 报价 $c_{ij}$
``` py
import numpy as np
c = np.array([[4, 8, 7, 15, 12],
              [7, 9, 17, 14, 17],
              [6, 9, 12, 8, 7],
              [6, 7, 14, 6, 10],
              [6, 9, 12, 10, 6]])   # 定义目标向量
x = cp.Variable((5, 5), integer = True) # 定义约束矩阵

obj = cp.Minimize(cp.sum(cp.multiply(c, x)))    # 构造目标函数
con = [0 <= x, x <= 1,
     cp.sum(x, aixs = 0, keepdims = True) == 1,
     cp.sum(x, axis = 1, keepdims = True) == 1] # 构造约束条件
prob = cp.Problem(obj, con)                     # 构造问题模型
prob.solve(solver = 'GLPK_MI')                  # 求解问题
print("最优值为：", prob.value)
print("最优解为：", x.value)
```

#### 2. 广义指派问题
软件求解不需要转化为标准指派问题，直接建立模型即可。

### 6.1.3 整数规划示例——装箱问题
例6.3 整数规划实例
``` py

```



## 6.2 非线性规划
分为有约束和无约束两大类

### 6.2.1 非线性规划的概念和理论
#### 1. 非线性规划模型
1. 非线性规划模型的一般形式
min f(x)
s.t.:
- $g_{i}(x)$ <= 0
- $h_{j}(x)$ = 0

2. max,>=可以通过相反数转化
定义：
- 可行域K
- 全局最优解—全局最优值（严格）
- 局部最优解-局部最优值（严格）

3. （线性规划的最优解存在，在可行域边界(特别是可行域顶点上达到)，且为全局最优解）
非线性规划的最优解可能在可行域的任何一点，一般算法得出局部最优解不能保证全局最优解


#### 2. 无约束非线性规划的求解
高数介绍求二元极值方法推广
- 黑塞矩阵：二阶偏导数矩阵
- 无约束优化问题有局部最优解的充分条件：连续二阶偏导，梯度0，二级梯度正定阵——最优解

#### 3. 有约束线性规划的求解
处理要求：
- 目标函数每次迭代时有所下降
- 解的可行性
  
常见处理思路：
- 可能的话，非线性问题转化为线性问题
- 约束问题转化为无约束问题

1. 求解有等式约束非线性规划的Lagrange乘数法
Lagrange定理：转化为无约束问题的求解

2. 求解有约束非线性规划的罚函数法
(罚函数法精度可能较差，除非算法达到实时，否则一般用软件工具库求解)
- 罚函数法的基本思想：
  利用目标函数和约束条件构造增广目标函数，将有约束非线性规划问题转化为一系列无约束非线性规划问题
- 代表性罚函数法：外部罚函数法（外点法）
  - 迭代点在可行域外部移动，迭代次数增加，惩罚力度增大，迫使迭代点向可行域靠近
  - 操作关键：不等式约束gi(x)<=0 等价于 等式约束max{0,gi(x)}=0
  - 构造增广目标函数T(x,M)，转为无约束问题min T(x, M)
  
### 6.2.2 非线性规划的Python求解
可以用scipy.optimize模块，cvxopt库cvxpy库
#### 1. 用scipy.optimize的minimize函数求解
例6.4 
``` py
# 程序文件Pex6_4.py
from scipy.optimize import minimize
from numpy import ones

def obj(x):
    x1, x2, x3 = x
    return (2+x1)/(1+x2)-3*x1+4*x3
LB = [0.1]*3
UB = [0.9]*3
bound = tuple(zip(LB, UB))                      # 生成决策向量界限的元组

res = minimize(obj, ones(3), bounds = bound)    # 第二个参数为初值
print(res.fun, '\n', res.success, '\n', res.x)  # 输出最优值、求解状态、最优解
```

例6.5 求解下列非线性规划问题
``` py
from scipy.optimize import minimize
import numpy as np

c1 = np.array([1, 1, 3, 4, 2])
c2 = np.array([-8, -2, -3, -1, -2])
A = np.array([[1, 1, 3, 4, 2], [1, 2, 2, 1, 6],
                 [2, 1, 6, 0, 0], [0, 0, 1, 1, 5]])
b = np.array([400, 800, 200, 200])

obj = lambda x: np.dot(-c1, x**2) + np.dot(-c2, x)
cons = {'type': 'ineq', 'fun': lambda x:b-A@x}
bd = [(0, 99) for i in range(A.shape[1])]
res = minimize(obj, np.ones(5)*90, constraints = cons, bounds = bd)
print(res)          # 输出解的信息
```

#### 2. 用cvxopt.solvers求解
（C5介绍了cvxopt.solvers解决线性规划）
利用cvxopt.solvers模块解决二次规划模型
- 二次规划：
  非线性规划的目标函数为决策向量x的二次函数
  约束条件全是线性的

- 该模块中二次规划标准型
  - min   1/2$x^{T}$P$x$ + $q^{T}$x
  - s.t.   Ax <= b
    ·····     Aeq·x = beq

``` py
# 程序文件Pex6_6.py
import numpy as np
from cvxopt import matrix, solvers

n = 3
P = matrix(0., (n, n))
P[::n+1] = [3, 2, 1.7]
q = matrix([3, -8.2, -1.95])
A = matrix([[1., 0, 1], [-1, 2, 0], [0, 1, 2]]).T
b = matrix([2., 2, 3])
Aeq = matrix(1., (1, n))
beq = matrix(3.)

s = solvers.qp(P, q, A, b, Aeq, beq)
print("最优解为：", s['x'])
print("最优值为：", s['primal objective'])
```

#### 3. 用cvxpy库求解
例6.7 求解非线性整数规划问题
``` py
import numpy as np
import cvxpy as cp

c1 = np.array([1, 1, 3, 4, 2])
c2 = np.array([-8, -2, -3, -1, -2])
a = np.array([1, 1, 1, 1, 1], [1, 2, 2, 1, 6], [2, 1, 6, 0, 0], [0, 0, 1, 1, 5])
b = np.array([400, 800, 200, 200])

x = cp.Variable(5, integer = True)
obj = cp.Minimize(c1*x**2+c2*x)
con = [0 <= x, x <= 99, a*x <= b]

prob = cp.Problem(obj, con)
prob.solve()
print("最优值为: ", prob.value)
print("最优解为: ", x.value)
```

### 6.2.3 飞行管理问题
