# 9.4.3 从一个类中导入任意数量的类
# 在同一个文件中创建普通汽车和电动汽车，需导入多个类（Car\ElectricCar）
# my_cars.py
from car import Car, ElectricCar

my_beetle = Car('volkswagen', 'beetle', 2019)#大众甲壳虫普通汽车
print(my_beetle.get_descriptive_name())

my_tesla = ElectricCar('tesla', 'roadster', 2019)#特斯拉Roadster电动汽车
print(my_tesla.get_descriptive_name())



# 9.4.4 导入整个模块
# 导入整个模块，再使用句点表示法访问需要的类module_name.CalssName
# 导入方式简单，代码易于阅读
# 不会发生名称冲突：创建类实例的代码都包含模块名，所以不会与当前文件使用的任何名称冲突
# 导入整个car模块，创建一辆普通汽车和一辆电动汽车
import car

my_beetle = car.Car('volkswagen', 'beetle', 2019)
print(my_beetle.get_descriptive_name())

my_tesla = car.ElectricCar('tesla', 'roadster', 2019)
print(my_tesla.get_descriptive_name())

