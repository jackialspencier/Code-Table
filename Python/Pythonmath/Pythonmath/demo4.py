import numpy as np
import pandas as pd
import sympy as sp
from scipy.optimize import fsolve
from scipy.integrate import quad
from sympy import symbols,Eq,solve,cos,sin,tan,sqrt,exp,log,Integral,pi,atan2
from scipy.optimize import differential_evolution

p = 1.7
b = p / 2 / np.pi
theta_initial = 16 * 2 * np.pi
time_duration = 300
num_sections = 223
head_length = 341 / 100
body_length = 220 / 100
dlt = (2*27.5) /100  # 板凳交错
section_length = np.array([head_length] + [body_length] * (num_sections - 1))  # 创建一个包含每节板凳长度的数组
distance = section_length-dlt # 计算每节板凳之间的距离
number=30

def arclength(theta):
    return np.sqrt(b**2 + (b * theta)**2)

def equations(vars, angle_prev, r_prev, dist):
    angle_i, r = vars
    eq1 = dist - np.sqrt(r**2 + r_prev**2 - 2 * r_prev * r * np.cos(angle_prev - angle_i))
    eq2 = r - b * angle_i
    return [eq1, eq2]

def eqinner(vars, a, b, dist, radius):
    x, y = vars
    d = np.sqrt(a**2 + (b-radius/3)**2)
    eq1 = x**2 + (y-radius/3*2) ** 2 - (radius/3)**2
    eq2 = x**2 + (y+radius/3) ** 2 - (radius/3*2)**2
    eq = np.sqrt((x-a)**2 + (y-b)**2) - dist
    if d < dist:
        return [eq1, eq]
    else:
        return [eq2, eq]
    
# 根据龙头位置theta, 计算向外一圈的点位的函数
def body_state(theta, r, radius):
    """得到确定龙头theta位置状态下, 整条龙各节的位置"""
    thetas = np.zeros(number+1)
    rs = np.zeros(number+1)
    thetas[0] = theta
    rs[0] = r
    x = np.zeros(number+1)
    y = np.zeros(number+1)
    x[0], y[0] = polar_to_cartesian(rs[0], thetas[0])
        
    for i in range(1, number+1):
        initial_guess = [thetas[i-1] + 0.5, rs[i-1]+0.1]  # 微调初始角度
        sol = fsolve(equations, initial_guess, args=(thetas[i-1], rs[i-1], distance[i-1]))
        thetas[i] = sol[0]       # 得到龙身点(r, theta)的theta
        rs[i] = thetas[i] * b    # 得到龙身点坐标的r
        # r, theta如果不合适,没有更新, 不是最终值
        
        if (rs[i] < radius):
            sol = fsolve(eqinner, initial_guess, args = (x[i-1], y[i-1], distance[i-1], radius))
            x[i], y[i] = sol
        else:
            x[i], y[i] = polar_to_cartesian(rs[i], thetas[i])
            
    return x, y

# 坐标转换函数polar_to_catersin
def polar_to_cartesian(r, theta):
    """将极坐标转换为直角坐标"""
    x = r * np.cos(theta)
    y = r * np.sin(theta)
    return x, y

# 计算待考虑碰撞龙头(与第二节端点)的x ,y坐标函数
def corner_point(x0, y0, x1, y1):
    """根据本块木板前后孔位的坐标计算本块木板的四个端点值"""
    orientation = atan2(y1-y0, x1-x0)
    fx = (x0-x1)/abs(x0-x1)
    fy = (y0-y0)/abs(y0-y1)
    mid_x0 = x0 + (27.5 / 100) * cos(orientation)*fx
    mid_y0 = y0 + (27.5 / 100) * sin(orientation)*fy
    mid_x1 = x1 - (27.5 / 100) * sin(orientation)*fx
    mid_y1 = y1 - (27.5 / 100) * sin(orientation)*fy
    left0_x = mid_x0 + 0.15 * cos(orientation - np.pi/2)
    left0_y = mid_y0 + 0.15 * sin(orientation - np.pi/2)
    right0_x = mid_x0 - 0.15 * cos(orientation - np.pi/2)
    right0_y = mid_y0 - 0.15 * sin(orientation - np.pi/2)
    left1_x = mid_x1 + 0.15 * cos(orientation - np.pi/2)
    left1_y = mid_y1 + 0.15 * sin(orientation - np.pi/2)
    right1_x = mid_x1 - 0.15 * cos(orientation - np.pi/2)
    right1_y = mid_y1 - 0.15 * sin(orientation - np.pi/2)
    ans = np.array([[left0_x, left0_y], [right0_x, right0_y], [left1_x, left1_y], [right1_x, right1_y]])
    return ans
    
    
# 计算点到直线距离的函数
def find_distance(x, y, x1, y1, x2, y2):
    """求点(坐标)到直线(由两点的坐标确定)的距离函数"""
    # 计算直线系数
    A = y2 - y1
    B = x1 - x2
    C = x2 * y1 - x1 * y2
    # 计算距离
    distance_point_to_line = abs(A * x + B * y + C) / np.sqrt(A**2 + B**2)
    return distance_point_to_line

# 计算等于0.15时对应的龙头theta值()
def g(vars, radius):
    """返回一个表示 min(点到直线距离)-0.15 的函数"""
    # 求龙身的位置
    x , y = vars
    xs = np.zeros(number)
    ys = np.zeros(number)
    xs, ys = body_state(x ,y , radius)
    
    # 求corner端点的位置
    points1 = corner_point(xs[0], ys[0], xs[1], ys[1])
    points2 = corner_point(xs[1], ys[1], xs[2], ys[2])
    points = np.vstack((points1, points2))
    
    # 求点到直线距离
    d = np.zeros((number-2)*8)
    j = 0
    for i in np.arange(3, number):
        for cp in range(8):
            d[j] = find_distance(points[cp][0], points[cp][1], xs[i], ys[i], xs[i+1], ys[i+1])*10 - 1.5
            j += 1
    min_distance = min(d)
    print('最小距离为',min_distance)
    if x**2 + y**2 > radius**2:
        equa1=(sqrt(x**2 + y**2) / b-atan2(y,x)) % (2*np.pi)  
    elif y>radius/3:
        equa1=abs(x**2 + (y-radius/3*2)**2 - (radius/3)**2)+abs(x-abs(x) )     
    else :
        equa1=abs(x**2 + (y+radius/3)**2 - (radius/3*2)**2)+abs(x+abs(x))   
    print(equa1) 
    return [equa1,min_distance]

for i in np.arange(0, 4.5, 0.1):
    radius_now = 4.5 - i
    sol, _, ier, msg = fsolve(g, [1., 1.], args = (radius_now, ), xtol=1e-8, full_output = True)
    print("半径为: ", radius_now,"时, 发生碰撞时龙头的位置: ", sol, "求解状态: ", ier)