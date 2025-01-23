import numpy as np
import pandas as pd
import sympy as sp
from scipy.optimize import fsolve

# 参数定义
p = 55 / 100  # 螺距，转换为米
speed_head = 1  # 龙头速度，单位 m/s
total_sections = 223
lengths = [341 / 100] + [220 / 100] * (total_sections - 2) + [220 / 100]  # 转换为米
print(lengths)
# 时间点生成与结果列表初始化
time_points = np.arange(0, 301, 1)  # 从0到300秒
angles = []
# angle0 = sp.symbols('angle0')
# r = lambda angle0: angle0 * p

def eq(x, y, p):
    return p*(0.5*(x * np.sqrt(1+x**2) + np.log(x + np.sqrt(1+x**2)))) - y
y_values = np.arange(0, 301, 1)

for t in time_points:
    # sol = sp.solve(eq.subs(y, t), x)
    sol = fsolve(eq, x0 = 0.0, args = (300 - t, p))
    angles.append((sol[0]))
    # print(sol)

# print(angles)
df = pd.DataFrame(angles)
df.to_excel("Demodata.xlsx")

# df.close()