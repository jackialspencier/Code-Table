from sympy.plotting import plot
from sympy.abc import x # 来自书的注释：引进符号变量x和常量pi
from sympy import pi# w试一下看看
from sympy.functions import sin, cos
plot((2*sin(x), (x, -6, 6)), (cos(x+pi/4), (x, -5, 5)))