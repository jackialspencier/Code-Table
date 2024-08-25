# 数据可视化：数值/非数值
# Matplotlib 数学绘图库
# 随机漫步概念——根据一系列随机决策生成的图表
# Plotly包，生成图表便于显示——Plotly来分析掷骰子的结果



##### 15.1 安装Matplotlib
# $ python -m pip install --user matplotlib
# $ python3 -m pip install --user matplotlib



##### 15.2 绘制简单的折线图
# mpl_squares.py
import matplotlib.pyplot as plt

squares = [1, 4, 9, 16, 25]
fig, ax = plt.subplots()
ax.plot(squares)

plt.show()

### 15.2.1 修改标签文字和线条粗细
# 改善可读性
# mpl_squares.py
import matplotlib.pyplot as plt

squares = [1, 4, 9, 16, 25]
fig, ax = plt.subplots()
ax.plot(squares, linewidth = 3)

# 设置图表标题并给坐标轴加上标签
ax.set_title("squares", fontsize = 24)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("value ^ 2", fontsize = 14)
# ax.set_title("平方数", fontsize = 24)
# ax.set_xlabel("值", fontsize = 14)
# ax.set_ylabel("值的平方", fontsize = 14)

# 设置刻度标记的大小
ax.tick_params(axis = 'both', labelsize = 14)

plt.show()

### 15.2.2 校正图形
# mpl_squares.py
import matplotlib.pyplot as plt
input_values = [1, 2, 3, 4, 5]
squares = [1, 4, 9, 16, 25]

fig, ax = plt.subplots()
ax.plot(input_values, squares, linewidth = 3)

# 设置图表标题并给坐标轴加上标签
#  -- snip --
ax.set_title("squares", fontsize = 24)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("squares", fontsize = 14)

# 设置刻度标记大小
ax.tick_params(axis = 'both', labelsize = 14)

plt.show()

### 15.2.3 使用内置样式
# 在终端会话执行以下命令：
# >>> import matplotlib.pyplot as plt
# >>> plt.style.available
# 即可看到众多Matplotlib已定义好的样式

# 使用这些样式，在生成图表的代码前添加以下代码行：
# mpl_squares.py
import matplotlib.pyplot as plt

int_values = [1, 2, 3, 4, 5]
squares = [1, 4, 9, 16, 25]

plt.style.use('seaborn-v0_8-darkgrid')
fig, ax = plt.subplots()
ax.plot(int_values, squares, linewidth = 3)

# 设置图表标题并给坐标轴加上标签
ax.set_title("squares", fontsize = 24)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("value^2", fontsize = 14)
# 设置坐标轴刻度标记大小
ax.tick_params(axis = 'both', labelsize = 14)

plt.show()

# 可以找出喜欢的
#['Solarize_Light2', '_classic_test_patch', '_mpl-gallery', '_mpl-gallery-nogrid', 'bmh', 'classic', 'dark_background', 'fast', 'fivethirtyeight', 'ggplot', 'grayscale', 'seaborn-v0_8', 'seaborn-v0_8-bright', 'seaborn-v0_8-colorblind', 'seaborn-v0_8-dark', 'seaborn-v0_8-dark-palette', 'seaborn-v0_8-darkgrid', 'seaborn-v0_8-deep', 'seaborn-v0_8-muted', 'seaborn-v0_8-notebook', 'seaborn-v0_8-paper', 'seaborn-v0_8-pastel', 'seaborn-v0_8-poster', 'seaborn-v0_8-talk', 'seaborn-v0_8-ticks', 'seaborn-v0_8-white', 'seaborn-v0_8-whitegrid', 'tableau-colorblind10']



### 15.2.4 使用scatter()绘制散点图并设置样式
# 绘制单个点，使用方法scatter()，传递一对x和y坐标——函数在指定位置绘制一个点
# catter_squares.py
import matplotlib.pyplot as plt

plt.style.use('seaborn-v0_8')
fig, ax = plt.subplots()
ax.scatter(2, 4)

plt.show()

# 设置图表样式
# 添加标题，标签，文本够大
import matplotlib.pyplot as plt

plt.style.use('seaborn-v0_8')
fig, ax = plt.subplots()
ax.scatter(2, 4, s = 200)
# 设置图表标题并给坐标轴加上标签
ax.set_title("squares", fontsize = 24)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("value^2", fontsize = 14)
# 设置刻度标记大小
ax.tick_params(axis = 'both', which = 'major', labelsize = 14)

plt.show()



### 15.2.5 使用scatter绘制一系列点
# 方式：向scatter传递两个分别包含x值和y值的列表
# scatter_squares.py
import matplotlib.pyplot as plt

x_values = [1, 2, 3, 4, 5]
y_values = [1, 4, 9, 16, 25] # Matplotlib从中依次从每个列表取一值绘制一点
plt.style.use('seaborn-v0_8')
fig, ax = plt.subplots()#(创建画布)
ax.scatter(x_values, y_values, s = 100)
# 设置坐标轴标题并指定标签
ax.set_title("squares", fontsize = 24)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("value^2", fontsize = 14)
# 设置刻度标记大小
ax.tick_params(axis = 'both', which = 'major', labelsize = 14)

plt.show()



### 15.2.6 自动计算数据
#手动计算列表 => Python循环完成
# scatter_squares.py
import matplotlib.pyplot as plt

x_values = range(1, 1001)# 包含数1~1000
y_values = [x**2 for x in x_values]

plt.style.use('seaborn-v0_8')
fig, ax = plt.subplots()
ax.scatter(x_values, y_values, s = 10)
# 设置图表标题、给坐标轴加上标签 $ -- snip --
ax.set_title("squares", fontsize = 24)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("value^2", fontsize = 14)

# 设置每个坐标轴取值范围
ax.axis([0, 1100, 0, 1100000])

plt.show()



### 15.2.7 自定义颜色
# scatter传递参数c
# 引号内放要使用的颜色名称
# 元组，包含0~1三个小数值(红、绿、蓝分量)，RGB颜色模式自定义颜色
# 1.颜色名称:
# ax.scatter(x_values, y_values, c = 'red', s = 10)
import matplotlib.pyplot as plt

x_values = range(1, 1001)
y_values = [x**2 for x in x_values]
plt.style.use('seaborn-v0_8')
fig, ax = plt.subplots()
ax.scatter(x_values, y_values, c = 'red', s = 10)
# 设置坐标轴标题并指定标签
ax.set_title("squares", fontsize = 24)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("value^2", fontsize = 14)
# 设置刻度
ax.tick_params(axis = 'both', which = 'major', labelsize = 14)
# 设置坐标轴取值范围
ax.axis([0, 1100, 0, 1100000])

plt.show()

# 2.RGB元组
# ax.scatter(x_values, y_values, c = (0, 0.8, 0), s = 10)
import matplotlib.pyplot as plt

x_values = range(1, 1001)
y_values = [x**2 for x in x_values]

plt.style.use('seaborn-v0_8')
fig, ax = plt.subplots()
ax.scatter(x_values, y_values, c = (0, 0.8, 0), s = 10)
# 设置坐标轴标题以及标签
ax.set_title("squares", fontsize = 24)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("value", fontsize = 14)
# 设置刻度
ax.tick_params(axis = 'both', which = 'major', labelsize = 14)
# 设置坐标轴范围
ax.axis([0, 1100, 0, 1100000])

plt.show()


### 15.2.8 使用颜色映射
# 颜色映射：一系列颜色，从其实颜色渐变到结束颜色
# 例如：小——浅，大——深
# key：告诉pyplot如何设置数据集中每个点的颜色
# 例：根据每个点y值设置其颜色
# scatter_squares.py
import matplotlib.pyplot as plt

x_values = range(1, 1001)
y_values = [x**2 for x in x_values]

plt.style.use('seaborn-v0_8')
fig, ax = plt.subplots()
ax.scatter(x_values, y_values, c = y_values, cmap = plt.cm.Blues, s = 10)
# 设置坐标轴标题和标签
ax.set_title("squares", fontsize = 24)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("value^2", fontsize = 14)
# 设置刻度
ax.tick_params(axis = 'both', which = 'major', labelsize = 14)
# 设置坐标轴范围
ax.axis([0, 1100, 0, 1100000])

plt.show()




### 15.2.9 自动保存图表
# plt.savefig()来代替plt.show()
# 第一个参数：以什么文件名保存图表（文件将存到scatter_squares.py所在目录）
# 第二个参数：将图标多余的空白区域裁剪掉。若要保留空白，省略该参数即可。
plt.savefig('squares_plot.png', bbox_inches = 'tight')
# 若和plt.show()同时使用，应放在plt.show()前，因为plt.show()会将图像清楚。









# 练习
# practice15-1：
# 显⽰前5个整数的⽴⽅值
import matplotlib.pyplot as plt

x_values = [1, 2, 3, 4, 5]
y_values = [1, 8, 27, 64, 125]

plt.style.use('seaborn-v0_8')
fig, ax = plt.subplots()
ax.scatter(x_values, y_values, c = (1, 0.5, 0.5), s = 10)

ax.set_title("cube", fontsize = 24)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("value^3", fontsize = 14)
ax.tick_params(axis = 'both', which = 'major', labelsize = 14)
ax.axis([0, 6, 0, 130])

plt.show()

# 显示前5000个整数的立方值
import matplotlib.pyplot as plt

x_values = range(1, 5001)
y_values = [x**3 for x in x_values]

plt.style.use('seaborn-v0_8')
fig, ax = plt.subplots()
ax.scatter(x_values, y_values, c = y_values, cmap = plt.cm.Blues, s = 10)

ax.set_title("cube", fontsize = 24)
ax.set_xlabel("value", fontsize = 14)
ax.set_ylabel("value^3", fontsize = 14)
ax.tick_params(axis = 'both', which = 'major', labelsize = 14)
ax.axis([0, 5500, 0, 140000000000])#哪来的5000^3

plt.show()







### 15.3 随机漫步

###15.3.1 创建RandomWalk类
# random_walk.py
from random import choice
class RandomWalk:
    """一个生成随机漫步数据的类。"""
    
    def __init__(self, num_points = 5000):
        """初始化随机漫步的属性"""
        self.num_points = num_points
    
        # 所有的随机漫步都始于（0，0）。
        self.x_values = [0]
        self.y_values = [0]