# 例3.2 同一图形界面画两个符号函数
# 程序文件 Pex3_3.py
from sympy.plotting import plot
from sympy.abc import x # 来自书的注释：引进符号变量x和常量pi
from sympy import pi# w试一下看看
from sympy.functions import sin, cos
plot((2*sin(x), (x, -6, 6)), (cos(x+pi/4), (x, -5, 5)))

# 例3.4 三维图形
# 程序文件Pex3_4.py
from pylab import rc
from sympy.plotting import plot3d
from sympy.abc import x, y
from sympy.functions import sin, sqrt
rc('font', size = 16)