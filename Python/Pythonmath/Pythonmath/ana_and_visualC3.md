## 3.3 用 SymPy做符号函数画图
### 1. 二维曲线画图
|||
| ---     | --- |
|基本格式：|plot(表达式， 变量取值范围， 属性 = 属性值)|
|多重绘制：|plot(表达式1， 表达式2， 变量取值范围，属性 = 属性值)
|         |plot((表达式1， 变量取值范围1), (表达式2， 变量取值范围2))|
|||

``` py
# 程序文件Pex3_3.py
from sympy.plotting import plot
from sympy.abc import x
fron sympy import pi
from sympy.functions import sin, cos
plot((2*sin(x), (x, -6, 6)), (cos(x+pi/4), (x, -5, 5)))
```

### 2. 三维曲线画图
``` py
# 程序文件Pex3_4.py
from pylab import rc # pylab为matploitlab接口 # runtime configuration，全局参数
from sympy.plotting import plot3d
from sympy.abc import x, y
from sympy.functions import sin, sqrt
rc('font', size = 16)
rc('text', usetex = True)
plot3d(sin(sqrt(x**2+y**2)), (x, -10, 10), (y, -10, 10),
     xlabel = '$x$', ylabel = '$y$')
```

### 3. 隐函数画图
plot_implicit函数可以绘制隐函数图像
plot中的Eq函数可以建立等式
``` py
# 程序文件Pex3_5_1.py
from pylab import rc
from sympy import plot_implicit as pt, Eq
from sympy.abc import x, y
rc('font', size = 16)
rc('text', usetex = True)
pt(Eq((x-1)**2+(y-2)**3, 4), (x, -4, 4), (y, -2, 4),
     xlabel = '$x$', ylabel = '$y$')
```

或使用匿名函数(lambda函数)合计如下程序
``` py
# 程序文件Pex3_5_2.py
from sympy import plot_implicit as pt
from sympy.abc import x, y
ezplot = lambda expr:pt(expr)
ezplot((x-1)**2 + (y-2)**3 - 4)
```


## 3.4 高等数学问题的符号解
SymPy可以处理三种类型的数据：整数、实数、有理数（分子和分母，可用Ration类来定义）
通过实例程序理解SymPy的概念和应用
### 1.求极限
``` py
# 程序文件Pex3_6.py
from sympy import *
x = symbol('x')
print( limit(sin(x)/x, x, 0) )
print( limit(pow(1+1/x, x), x, oo) ) # 两个小o，表示正无穷
```

### 2.求导数
``` py
from sympy import *
x, y = symbols('x y') # 定义两个符号变量
z = sin(x) + x**2 + exp(y)  # 构造符号表达
print("关于x的二阶偏导数为：", diff(z, x, 2))
print("关于y的一阶偏导数为", diff(z, y))
```

### 3.级数的求和
``` py
# 程序文件Pex3_8.py
from sympy import *
k, n = symbols('k  n')
print(summation(k**2, (k, 1, n)))
print(factor(summation(k**2, (k, 1, n))))   # 把计算结果因式分解
print(summation(1/k**2, (k, 1, oo)))        # 这里两个小o表示正无穷
```

### 4.泰勒展开
``` py
# 程序文件Pex3_9.py
from pylab import rc
from sympy import *
from sympy.plotting import *
rc('font', size = 16)
rc('text', usetex = True)
x = symbols('x')
y = sin(x)
for k in range(3, 8, 2):
    print(y.series(x, 0, k))    # 等价于print(series(y, x, 0, k))
plot(y, series(y, x, 0, 3).removeO(), series(y, x, 0, 5).removeO(),
    series(y, x, 0, 7).removeO(), (x, 0, 2), xlabel = '$x$', ylabel = '$y$')
```

### 5.不定积分和定积分
``` py
from sympy import integrate, symbols, sin, pi, oo   # oo也是在库中的
x = symbols('x')
print(integrate(sin(2*x), (x, 0, pi)))
print(integrate(sin(x)/x, (x, 0, oo)))
```

### 6.求解代数方程（方程组）的符号解
``` py
# 程序文件Pex3_11.py
from sympy import *
x, y = symbols('x y')   # y:w来干嘛？
print(solve(x**3-1, x))
print(solve((x-2)**2*(x-1)**3-1, x))
print(roots((x-2)**2*(x-1)**3-1, x))
```

``` py
# 程序文件Pex3_12.py
from sympy.abc import x, y
from sympy import solve
s = solve([x**2+y**2-1, x-y], [x, y])
print("方程的解为：", s)
```

``` py
# 程序文件Pex3_13.py
from sympy import *
x = symbols('x')
y = 2*x**3-5*x**2+x
x0 = solve(diff(y, x), x)
print("驻点的精确解为：", x0)
print("驻点的浮点数表示为：", [x0[i].n() for i in range(len(x0))])
y0 = [y.subs(x, 0), y.subs(x, 1), y.subs(x, x0[0].n())]
print("三个点的函数值分别为：", y0)
```

### 7.求微分方程的符号解
将符号变量声明为函数类型的两种方法
``` py
y = Function('y')
y = symbols('y', cls = Function)
```
求微分方程的通解
``` py
# 程序文件Pex3_14.py
from sympy import *
x = symbols('x')
y = symbols('y', cls = Function)
eq1 = diff(y(x), x, 2) - 5*diff(y(x),x) + 6*y(x)
eq2 = diff(y(x), x, 2) - 5*diff(y(x),x) + 6*y(x) - x*exp(2*x)
print("齐次方程的解为：", dsolve(eq1, y(x)))
print("非齐次方程的解为：", dsolve(eq2, y(x)))
```

求微分方程的解
``` py
# 程序文件Pex3_15.py
from sympy import *
x = symbols('x')
y = symbols('y', cls = Function)
eq1 = diff(y(x), x, 2) - 5*diff(y(x), x) + 6*y(x)
eq2 = diff(y(x), x, 2) - 5*diff(y(x), x) + 6*y(x) - x*exp(2*x)
print("初值问题的解为：{}".format(dsolve(eq1, y(x), isc = {y(0):1,
     diff(y(x), x).subs(x, 0):0})))
y2 = dsolve(eq2, y(x), isc = {y(0):1, y(2):0})
print("初值问题的解为：{}".format(y2))
```

## 3.5 高等数学问题的数值解
### 3.5.1 泰勒级数与数值导数
#### 1.泰勒级数
``` py
# 程序文件Pex3_16.py
import numpy as np
import matplotlib.pylot as plt
def fac(n): return (1 if n<1 else n*fac(n-1))
def item(n, x): return (-1)**n*x**(2*n+1)/fac(2*n+1)
def mysin(n, x): return (0 if n < 0 else mysin(n-1,x)+item(n,x)) # 自定义函数mysin得到mysin(自变量，级数)泰勒展开式
x = np.linspace(-2*np.pi, 2*np.pi, 101)
plt.plot(x, np.sin(x), '*-')
str = ['v-', 'H--', '-.']
for n in [1, 2, 3]: plt.plot(x, mysin(2*n-1, x), str[n-1])
plt.legend(['sin', 'n=1', 'n=3', 'n=5'])
plt.savefig('figure3_16.png', dpi = 500)
plt.show()
```

#### 2.数值导数
- 一阶导数一阶精度
- 一阶导数二阶精度
- 二阶导数估计式
``` py
import numpy as np, numpy.linalg as ng
import matplotlib.pylot as plt
N = 4; v = 1.0; d = 200.0; time = 400.0; divs = 201
xy = np.array([[-d, d], [d, d], [d, -d], [-d, -d]])
T = np.linspace(0, time, divs)
xyn = np.empty((4, 2))
Txy = xy
for n in range(1, len(T)):
     for i in [0, 1, 2, 3]:
          j = (i+1)%4; dxy = xy[j] - xy[i]
          dd = dxy/ng.norm(dxy)    # 单位化向量
          xyn[i] = xy[i] + v*dt*dd # 计算下一步的位置
     Txy = np.c_[Txy, xyn]
     xy = xyn.copy()
for i in range(N): plt.plot(Txy[i, ::2], Txy[i, 1::2])
plt.savefig("figure3_17.png", dpi=500); plt.show()
```

### 3.5.2 数值积分
#### 1. 一重积分
- 梯形公式
- 辛普森计算公式
- quad函数
``` py
# 程序文件Pex3_18.py
import numpy as np
from scipy.integrate import quad
def trapezoid(f, n, a, b):
     xi = np.linspace(a, b, n); h = (b-a)/(n-1)
     return h*( sum(f(xi)) - (f(a)+f(b))/2 )
def simpson(f, n, a, b):
     xi, h = np.linspace(a, b, 2*n+1), (b-a)/(2.0*n)
     xe = [f(xi[i]) for i in range(len(xi)) if i % 2 == 0]
     xo = [f(xi[i]) for i in range(len(xi)) if i % 2 != 0]
     return h*(2*np.sum(xe) + 4*np.sum(xo) - f(a) - f(b))/3.0
a = 0; b = 1; n = 1000
f = lambda x: np.sin(np.sqrt(np.cos(x)+x**2))
print("梯形积分I1 = ", trapezoid(f, n, a, b))
print("辛普森积分I2 = ", simpson(f, n, a, b))
print("Scipy积分I3 = ", quad(f, a, b))
```

#### 2. 多重积分
调用SciPy库中的函数直接求数值解，**dblquad, tplquad**
- 被积函数格式func(y, x), 最外层x积分区间[a,b], 内层y积分区间[gfun(x), hfun(x)]
  ``` py
  dblquad(func, a, b, gfun, hfun, args = (), epsabs = 1.49e-08, epsrel = 1.49e-08)
  ```
- 被积函数格式func(z, y, x), 最外层x积分区间[a,b], 中间层y积分区间[gfun(x),hfun(x)]，
  最内层z积分区间[qfun(x,y), rfun(x,y)]
  ``` py
  tplquad(func, a, b, gfun, hfun, qfun, rfun,
          args = (), epsabs = 1.49e-08, epsrel = 1.49e-08)
  ```
___
例3.19
``` py
# 程序文件Pex3_19.py
import numpy as np
from scipy.integrate import dblquad
f1 = lambda y, x: x*y**2
print("I1 = ", dblquad(f1, 0, 2, 0, 1))
f2 = lambda y, x: np.exp(-x**2/2) * np.sin(x**2+y)
bd = lambda x: np.sqrt(1-x**2)
print("I2 = ", dblquad(f2, -1, 1, lambda x: -bd(x), bd))
```

例3.20
``` py
# 程序文件Pex3_20.py
import numpy as np
from scipy.integrate import tplquad
f = lambda z, y, x: z*np.sqrt(x**2+y**2+1)
ybd = lambda x: np.sqrt(2*x-x**2)
print("I = ", tplquad(f, 0, 2, lambda x: -ybd(x), ybd, 0, 6))
```

### 3.5.3 非线性方程（组）数值解
#### 1. 二分法求根
#### 2. 牛顿迭代法求根
#### 3. 用SciPy工具库求解非线性方程组
例3.21 使用二分法、牛顿迭代法、直接调用SciPy库求解
``` py
# 程序文件Pex3_21.py
import numpy as np
from scipy.optimize import fsolve
def binary_search(f, eps, a, b):	# 二分法函数
	c = (a+b)/2
	while np.abs(f(c))>eps:
		if f(a) * f(c) < 0: b = c
		else: a = c
		c = (a+b)/2
	return c
def newton_iter(f, eps, x0, dx = 1E-8)	# 牛顿迭代法函数
	def diff(f, dx = x):	# 求数值导数函数
		return lambda x: (f(x+dx) - f(x-dx))/(2*dx)
	df = diff(f, dx)
	x1 = x0 - f(x0)/df(x0)
	while np.abs(x1-x0) >= eps:
		x1, x0 = x1 - f(x1)/df(x1), x1
	return x1
f = lambda x: x**3+1.1*x**2+0..9*x-1.4
print("二分法求得的根为：", binary_search(f, 1E-6, 0, 1))
print("牛顿迭代法求得的根为：", newton_iter(f, 1E-6, 0))
print("直接调用SciPy求得的根为：", fsolve(f, 0))
```

#### 4. 用fsolve求非线性方程组的数值解
``` py
# 程序文件Pex3_22_1.py
from numpy import sin
from scipy.optimize import fsolve
f = lambda x: [5*x[1]+3, 4*x[0]**2-2*sin(x[1]*x[2]), x[1]*x[2]-1.5]
print("result = ", fsolve(f, [1.0, 1.0, 1.0]))	# 第二个值是解的初始猜测
```

``` py
# 程序文件Pex3_22_2.py
from numpy import sin
from scipy.optimize import fsolve
def Pfun(x):
	x1, x2, x3 = x.tolist()	# x转换成列表
	return 5*x2+3, 4*x1**2-2*sin(x2*x3), x2*x3-1.5
print("result = ", fsolve(Pfun, [1.0, 1.0, 1.0]))
```

### 3.5.4 函数极值点的数值解
#### 1. 一元函数的极值点
例3.23 函数在[0, 3]上的极小点
``` py
# 程序文件Pex3_23.py
from numpy import exp, cos
from scipy.optimize import fminbound
f = lambda x: exp(x)*cos(2*x)
x0 = fminbound(f, 0, 3)
print("极小点为:{},极小值为{}".format(x0, f(x0)))
```
例3.24 函数在0附近的一个极小点
``` py
# 程序文件Pex3_24.py
from numpy import exp, cos
from scipy.optimize import fminbound
f = lambda x: exp(x)*cos(2*x)
x0 = fmin(f, 0)
print("极小点为:{}, 极小值为{}".format(x0, f(x0)))
```

#### 2. 多元函数的极值点
例3.25 二元函数的极小值
``` py
from scipy.optimize import minimize
f = lambda x: 100*(x[1]-x[0]**2)*2 + (1-x[0])**2
x0 = minimize(f, [2.0, 2.0, 2.0])
print("极小点为{}, 极小值为{}".format(x0.x, x0.fun))
```

## 3.6 线性代数问题的符号和数值解
行列式求值,特殊矩阵构建,求特征值特征向量,转置和逆阵,删除行列,基本算术运算
### 3.6.1 线性代数问题的符号解
#### 1. 矩阵的运算

### 3.6.2 线性代数问题的数值解
### 3.6.2 求超定线性方程组的最小二乘解