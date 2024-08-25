# 9.4.1 导入单个类
# 导入Car类并创建实例
from car import Car

my_new_car = Car('audi', 'a4', 2019)
print(my_new_car.get_descriptive_name())

my_new_car.odometer = 23
my_new_car.read_odometer()
