# 第八章 微分方程模型
## 8.1 微分方程模型的求解方法
高数介绍了一些特殊类型微分方程的求解方法
大量微分方程过于复杂无法求出解析解--用数值解法，求得微分方程近似解

### 8.1.1 微分方程的数值解
数值解法：y(x)在若干点处的近似值yn的方法
建立数值解法，首先要离散化，一般采取以下几种方法：
1. 用差商近似导数
2. 用数值积分方法
3. 泰勒多项式近似（得到数值解公式and易于估计截断误差）

### 8.1.2 用Python求解微分方差
#### 1. 符号解法
第三章介绍过微分方程符号解，以下再介绍几个例子：
例8.1 求微分方程特解
``` py
# 程序文件*_1.py
from sympy.abc import x
from sympy import diff, dsolve, simplify, Function

y = Function('y')
eq = diff(y(x), x, 2) + 2*diff(y(x), x, 1) + 2*y(x) # 定义方程
con = {y(0): 0, diff(y(x), x).subs(x, 0): 1}        # 定义初值条件
y = dsolve(eq, ics = con)

print(simplify(y))
```

例8.2 求下述微分方程的解
``` py
# 程序文件Pex8_2.py
from sympy.abc import x
from sympy import Function, dsolve, diff, sin

y = Function('y')
eq = diff(y(x), x, 2) + 2*diff(y(x), x) + 2*y(x) - sin(x)   # 定义方程
con = {y(0): 0, diff(y(x), x).subs(x, 0): 1}                # 定义初值条件
y = dsolve(eq, ics = con)

print(y)
```

例8.3 求微分方程组的解
``` py
# 程序文件Pex8_3.py
import sympy as sp
t = sp.symbols('t')
x1, x2, x3 = sp.symbols('x1, x2, x3', cls = sp.Function)
eq = [x1(t).diff(t) - 2*x1(t) + 3*x2(t) - 3*x3(t),
      x2(t).diff(t) - 4*x1(t) + 5*x2(t) - 3*x3(t),
      x3(t).diff(t) - 4*x1(t) + 4*x2(t) - 2*x3(t)]
con = {x1(0): 1, x2(0): 2, x3(0): 3}
s = sp.dsolve(eq, ics = con)
print(s)
```
(续)更简洁：
``` py
# 程序文件PEx8_3_2.py
import sympy as sp

t = sp.symbols('t')
x1, x2, x3 = sp.symbols('x1:4', cls = sp.Function)
x = sp.Matrix(x1(t), x2(t), x3(t))
A = sp.Matrix([[2, -3, 3], [4, -5, 3], 4, -4, 2])
eq = x.diff(t)-A*x
s = sp.dsolve(eq, ics = {x1(0): 1, x2(0): 2, x3(0):(3)})

print(s)
```

#### 2. 数值解法
scipy.integrate模块的odient函数求常微分方程数值解
基本调用格式
``` py
sol = odient(func, y0, t)
# func：风衣微分方程的函数/匿名函数
# y0：初始条件的序列
# t：自变量取值的序列
# 返回值sol是一个n列的矩阵，第i列对应第i个矩阵的数值解
```

例8.4 求微分方程在1<=x<=10上步长0.5的数值解
``` py
# 程序文件ex8_4.py
from scipy.integrate import odeint
from numpy import arange

dy = lambda y, x: -2*y + x**2 + 2*x
x = arange(1, 10.5, 0.5)
sol = odient(dy, 2, x)

print("x = {}\n对应的数值解y = {}".format(x, sol.T))
```

例8.5 求8.1的数值解，在同一个图形界面上画出符号解和数值解的曲线
``` py
# 程序文件Pex8_5.py
from scipy.integrate import odeint
from sympy.abc import t
import numpy as np
import matplotlib.pyplot as plt

def Pfun(y, x):
    y1, y2 = y
    return np.array([y2, -2*y1 - 2*y2])   # 列表好像也能跑
x = np.arange(0, 10, 0.1)
sol = odeint(Pfun, [0.0, 1.0], x)

plt.rc('font', size = 16)   
plt.rc('font', family = 'SimHei')
plt.plot(x, sol[:, 0], 'r*', label = "数值解")      # 中文显示how?
plt.plot(x, np.exp(-x)*np.sin(x), 'g', label = "符号解曲线")
plt.legend()
# plt.savefig("figure8_5.png")
plt.show()
```

例8.6 Lorenz模型的混沌效应
图1：有限区域内运动，测度为0，蝴蝶效应（？）
图2：初值接近，解差异随时间增加逐渐增大，动力学对初值敏感性直观体现。混沌态，混沌运动是确定性系统中存在的随机性
``` py
from scipy.integrate import odeint
import numpy as np
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt

def lorenz(w, t):
    sigma = 10; rho = 28; beta = 8/3.   # beta不需要控制浮点数吗（书上8/3）
    x, y, z = w
    return np.array([sigma*(y-x), rho*x-y-x*z, x*y-beta*z])
t = np.arange(0, 50, 0.1)               # 创建时间点
sol1 = odeint(lorenz, [0.0, 1.0, 0.0], t)       # 第一个初值问题求解
sol2 = odeint(lorenz, [0.0, 1.0001, 0.0], t)    # 第二个初值问题求解

plt.rc('font', size = 16) # plt.rc('text', usetex = True)
ax1 = plt.subplot(121, projection = '3d')           # 设置画布
ax1.plot(sol1[:, 0], sol1[:, 1], sol1[:,2], 'r')    # 根据xyz画图
ax1.set_xlabel('x')                                 # 设置标签x
ax1.set_ylabel('y')                                 # 设置标签y
ax1.set_zlabel('z')                                 # 设置标签z

ax2 = plt.subplot(122, projection = '3d')
ax2.plot(sol1[:, 0] - sol2[:, 0], sol1[:, 1] - sol2[:, 1], sol1[:, 2] - sol2[:, 2], 'g')
ax2.set_xlabel('x')
ax2.set_ylabel('y')
ax2.set_zlabel('z')

plt.savefig("figure8_6.png", dpi = 500)
plt.show()
print("sol1 = ", sol1, '\n\n', 'sol1 - sol2 = ', sol1 - sol2)
```
为什么不是光滑的曲线是折现
为什么没有列出全部,print出来的一部分是省略号

## 8.2 微分方程建模方法
方法步骤:
1. 根据实际要求 确定要研究的量(自变量,未知的函数,必要参数等),确定坐标系
2. 找出量满足的 基本规律
3. 运用规律 列出方程和定解条件

### 1. 按规律直接列方程
``` py
# 程序文件Pex8_7.py
import sympy as sp
sp.var('t', 'k')        # 定义符号变量t, k
u = sp.var('u', cls = sp.Function)          # 定义符号函数
eq = sp.diff(u(t), t) + k * (u(t) - 24)     # 定义方程
uu = sp.dsolve(eq, ics = {u(0): 150, u(1): 100})    # 求微分方程的符号解
print(uu)

kk = sp.solve(uu, k)    # kk返回值是列表,可能有多个解 # 根据u(t)=...反解出k
k0 = kk[0].subs({t: 10.0, u(t): 100.0})     # 带入含u(t)和t的k的符号解得出具体值
print(kk, '\t', k0)

u1 = uu.args[1]                 # 提取出符号表达式
u0 = u1.subs({t: 20, k: k0})    # 代入具体值
print("20分钟后的温度为: ", u0)
```

### 2. 微元分析法
例8.8 水从小孔流出的过程中水面高度h与时间t的关系
``` py
import numpy as np

sp.var('h')                     # 定义符号变量
sp.var('t', cls = sp.Function)  # 定义符号函数
g = 9.8

eq = t(h).diff(h) - 10000*sp.pi / 0.62 / sp.sqrt(2*g) * (h**(3/2)-2*h**(1/2))   # 定义方程
t = sp.dsolve(eq, ics = {t(1): 0})
t = sp.simplify(t)

print(t.args[1].n(9))
```

### 3. 模拟近似法
例8..9 交通管理问题
为正行驶在交叉路口或离交叉路口太近而无法停下的车辆通过路口,红绿灯转换间设置黄灯
那么,黄灯亮多长时间比较合适?
分析: 黄灯状态持续时间=驾驶员反应时间 + 车通过交叉口路口的时间 + 通过刹车距离所需时间
量:
- 法定速度 $v_{0}$
- 交通路口长度 I
- 典型车身长度 L
  
计算:
- 车通过路口时间: $(I+L)/v_{0}$
- 刹车距离:x(t0) = $v_{0}^{2}/2μg$ (解微分方程得到-----------------------------?)
- 黄灯状态时间: $T = (x(t_{0})+I+L)/v_{0} + T_{0}$ 
  (代入得) $T = v_{0}/2μg + (I+L)/v_{0} + T_{0}$

数据模拟选择:
- $T_{0}$ = 1s, L = 4.5m, I = 9m, μ取具有代表性得0.7, 得到 $v_{0}$=45, 65, 80 (km/h)的黄灯时间T

``` py
# 程序文件Pex8_9.py
from numpy import array
v0 = array([45, 65, 80])
T0 = 1; L = 4.5; I = 9; mu = 0.7; g = 9.8
T = v0/(2*mu*g)+(I+L)/v0+T0
print(T)
```

## 8.3 微分方程模型实例


## 8.4 拉氏变换求常微分方程(组)的符号解