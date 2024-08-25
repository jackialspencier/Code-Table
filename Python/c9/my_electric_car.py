# 9.4.2 在一个模块中储存多个类
# 同一个模块的类之间英寸在相关性，
# 可根据需要在一个模块中储存任意数量的类

# 导入ElectricCar类，并创建一辆电动汽车
# my_electric_caar.py
from car import ElectricCar#只需要import这一个吗
my_tesla = ElectricCar('tesla', 'model s', 2019)

print(my_tesla.get_descriptive_name())
my_tesla.battery.describe_battery()
my_tesla.battery.get_range()