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