#第八章 函数
#8.1定义函数
def greet_user():
    """显示简单的问候语"""
    print("Hello!")

greet_user()
#8.1.1向函数传递信息
def greet_user(username):
    """显示简单的问候语"""
    print(f"Hello,{username.title()}!")

greet_user('jesse')
greet_user('sarah')
#8.1.2实参和形参
#练习
#8-1消息
def display_message():
    print("We are learning some basic information about fuction.")
    
display_message()
#8-2喜欢的函数
def favorite_book(title):
    print(f"One of my favorite books is {title}.")

favorite_book("Alice in Wonderland")
#8.2传递参数
#8.2.1位置实参
def describe_pet(animal_type, pet_name):
    """"显示宠物信息"""
    print(f"\nI have a {animal_type}.")
    print(f"My {animal_type}'s name is {pet_name.title()}.")

describe_pet('hamster','harry')
#a.多次调用函数
def describe_pet(animal_type, pet_name):
    """"显示宠物信息"""
    print(f"\nI have a {animal_type}.")
    print(f"My {animal_type}'s name is {pet_name.title()}.")
    
describe_pet('hamster', 'harry')
describe_pet('dog','willie')

def describe_pet(pet_name,animal_type):
    "显示宠物信息"
    print(f"\nI have a{animal_type}.")
    print(f"My {animal_type}'s name is {pet_name.title()}.")

describe_pet('hamster', 'harry')
#8.2.2关键字实参
def describe_pet(animal_type, pet_name):
    """显示宠物信息"""
    print(f"\nI have a {animal_type}.")
    print(f"My {animal_type}'s name is {pet_name.title()}.")
    
describe_pet(animal_type='hamster', pet_name='harry')
describe_pet(pet_name='harry', animal_type="hamster")
#8.2.3默认值
def describe_pet(pet_name, animal_type='dog'):
    """显示宠物信息"""
    print(f"\nI have a {animal_type}.")
    print(f"My {animal_type}'s name is {pet_name.title()}.")

describe_pet('jesse')
describe_pet('danniel', 'pig')
describe_pet(pet_name='jimmy')
describe_pet(pet_name='norlan', animal_type='dragon')
describe_pet(animal_type='dragon', pet_name='norlan')

describe_pet('jim', animal_type="snake")
#describe_pet(animal_type='monster', 'lalalay')
#8.2.4等效的函数调用
describe_pet('jim', animal_type="snake")
#describe_pet(animal_type="monster", "lalalay")
#8.2.5避免实参错误
def describe_pet(animal_type, pet_name):
    """显示宠物信息"""
    print(f"I have a {animal_type}.")
    print(f"My {animal_type}'s is {pet_name.title()}.")
    
#describe_pet('dog')
#describe_pet()
#describe_pet("cat",'dog','jim')
#练习
#8-3T恤
def make_shirt(size, pattern):
    """制作特定尺码、字样的T恤"""
    print(f"\nThe T-shirt should be made to be {size} size with the pattern '{pattern}' on it.")

make_shirt('L','free')
make_shirt(pattern='free', size='L')
#8-4大号T恤
def make_shirt(size='Large', pattern='I love Python'):
    """制作特定尺码、字样的T恤"""
    print(f"\nWe will make a {size} T-shirt with '{pattern}' on it.")

make_shirt()
make_shirt('Middle')
make_shirt(size='middle')
make_shirt(size='small', pattern='I love computer.')
#8-5城市
def describe_city(name, country):
    """显示城市信息"""
    print(f"{name.title()} is in {country.title()}.")

describe_city("reykjavik", 'iceland')
def describe_city(name, country='China') :
    """显示城市信息"""
    print(f"{name.title()} is in {country.title()}.")#有默认值的方法使用全紫色诶。

describe_city('beijing')
describe_city(name='shanghai')
describe_city('hampton','america')
#8.3返回值
#8.3.1返回简单值
def get_formatted_name(first_name, last_name):
    """返回整洁的姓名"""
    full_name=f"{first_name.title()} {last_name.title()}"
    return full_name.title()

musician=get_formatted_name('jimi', 'hendrix')
print(musician)    
#8.3.2让实参变成可选的
def get_formatted_name(first_name, middle_name, last_name):
    """显示整洁的姓名"""
    full_name = f"{first_name} {middle_name} {last_name}"
    return full_name.title()

musician=get_formatted_name('john','lee','hooker')
print(musician)

def get_formatted_name(first_name, last_name, middle_name=''):
    """显示整洁的姓名"""
    full_name=f"{first_name} {middle_name} {last_name}"
    return full_name.title()

musician=get_formatted_name('john', 'hooker', 'lee')
print(musician)
musician=get_formatted_name('jimi', 'hendrix')
print(musician)

def get_formatted_name(first_name, last_name,middle_name=''):
    """显示整洁的姓名"""
    if middle_name:
        full_name=f"{first_name} {middle_name} {last_name}"
    else:
        full_name=f"{first_name} {last_name}"
    return full_name.title()

musician=get_formatted_name('jimi', 'hendrix')
print(musician)
musician=get_formatted_name('john', 'hooker', 'lee')
print(musician)

a= "aa" 
b= "bb"
c=f"{a}{b}".title()
print(c)

def build_person(first_name, last_name):
    """返回一个字典"""
    person={'first':first_name,'second_name':last_name}
    return person

musician=build_person('jimi','hendrix')
print(musician)

def build_person(first_name, last_name, age=None):
    """返回一个字典"""
    if age:#记得if后的缩进
        person = {'first':first_name, 'last':last_name, 'age':age}
    else:
        person={'first':first_name, 'last':last_name}
    return person

musician=build_person('jimi', 'hendrix', 27)
print(musician)

def build_person(first_name, last_name, age=None):
    person={'first':first_name, 'last':last_name}
    if age:#字典某个参数的有无的独特处理方法，先创建基本的，再判断是否添加。而不是直接判断创建哪种。
        person['age']=age
    return person

musician=build_person('jimi', 'hendrix', age=27)#混用关联方式。
print(musician)    
musician=build_person('jimi','hendrix',age='27')#此时被当成字符串。
print(musician)
#8.3.4结合使用函数和while循环
def get_formatted_name(first_name, last_name):
    """返回整洁的姓名"""
    full_name=f"{first_name} {last_name}"
    return full_name

#这是一个无限循环
# while True:
#     print("\nPlease tell me your name:")
#     first_name=input("First_name:")
#     last_name=input("Last_name:")
    
#     formatted_name=get_formatted_name(first_name, last_name)
#     print(f"Hello, {formatted_name}!")

def get_formatted_name(first_name, last_name):
    """返回整洁的姓名"""
    full_name=f"{first_name} {last_name}"
    return full_name.title()

# while True:
#     print("\nPlease tell me your name:")
#     print("(enter 'q' at any time to quit)")
    
#     f_name=input("First name:")
#     if f_name=='q':
#         break
#     l_name=input("Last_name:")
#     if l_name=='q':
#         break
    
#     formatted_name= get_formatted_name(f_name, l_name)
#     print(f"\nHello, {formatted_name}!")
#练习
#8-6
def city_country(city_name, country):
    """返回城市信息"""
    info=f"{city_name}, {country}"
    return info.title()

Beijing_info=city_country('Beijing', 'China')
print(Beijing_info)
Shanghai_info=city_country('Shanghai', 'China')
print(Shanghai_info)
London_info=city_country('London', 'British')
print(London_info)
#8-7专辑
# def make_album(singer_name, album_name):
#     """返回一个字典"""
#     album={'singer':singer_name,'album':album_name}
#     return album

# album1=make_album('5summer', 'Teeth')
# album2=make_album('Billie Eshley', 'Bad Guy')
# album3=make_album('Ingrid', 'Afterlife')
# print(album1)
# print(album2)
# print(album3)

def make_album(singer_name, album_name, song_number=None):
    """返回一个字典"""
    album={'singer':singer_name, 'album':album_name}
    if song_number:
        album['songs']=song_number#这里应该是等号！！！
        
    return album

album4=make_album('Ni/Co', 'Bleeding Love')
album5=make_album('Ed Sheeran', 'Shape of You', song_number=12)
print(album4)
print(album5)
#8-8
def make_album(singer_name, album_name, song_number=None):
    """返回一个字典"""
    album={'singer': singer_name, 'album': album_name}
    if song_number:
        album['songs']=song_number
    return album#别忘了返回啊大哥！

album4=make_album('Ni/Co', 'Bleeding Love')
album5=make_album('Ed Sheeran', 'Shape of You', song_number=12)
print(album4)
print(album5)
album_0=make_album('aa', 'bb', 'c')
print(album_0)

# active=True
# while active:#用了变量这里就别直接打True了啊喂！分清楚你用的是哪种停止循环方式！
#     print("Please tell me something about an album:")
#     print("(enter 'q' at any time to quit)")
#     s_name=input("Singer:")
#     if s_name=='q':
#         active=False
#     else:
#         a_name=input("Album:")
#         if a_name=='q':
#             active=False
#         else:
#             album_6=make_album(s_name, a_name)
#             print(album_6)
#可以不用每次判断后都选择继续执行或不执行后面的代码而缩进，
# 真正关注的只要是print受到了限制即可，这样本次执行不会有输出，
# 只消等待本次执行结束while判定结束循环即可。
# break确实可以不执行剩下的代码，但不强求二者效果等同。
# active=True#要使用标志，你得先定义，你得在while语句中用上！！
# while active:
#     print("\nPlease tell me something about a album:")
#     print("(enter 'q' at any time to stop)")
    
#     s_name=input("Singer:")
#     a_name=input("Album:")
    
#     if s_name=='q' or a_name=='q':
#         active=False
#     else:
#         album_7=make_album(s_name, a_name)
#         print(f"\n{album_7}")
#8.4传递列表
def greet_users(names):
    """向列表中的每位用户发出简单的问候"""
    for name in names:
        msg=f"Hello, {name.title()}!"
        print(msg)
    
usernames=['hannah', 'ty', 'margot']
greet_users(usernames)
#8.4.1在函数中修改列表
unprinted_designs=['phone case', 'robot pendant', 'dodecahedron']
completed_models=[]

#模拟打印每个设计，知道没有未打印的设计为止。
#打印每个设计后，都将其移到列表completed_models中
while unprinted_designs:
    current_design=unprinted_designs.pop()
    print(f"Printing model: {current_design}")
    completed_models.append(current_design)
    
#显示打印好的所有模型：
print("\nThe following models have been completed:")
for completed_model in completed_models:
    print(completed_model)
    
def print_models(unprinted_designs, completed_models):
    """
    模拟打印每个设计，知道没有未打印的设计为止。
    打印每个设计后，都将其移动到列表completed_models中。
    """
    while unprinted_designs:
        current_design=unprinted_designs.pop()
        print(f"Printing model: {current_design}")
        completed_models.append(current_design)

def show_completed_models(completed_models):
    """显示所有打印好的模型"""
    print("\nThe following models have been completed:")
    for completed_model in completed_models:
        print(completed_model)

#这里列表作为参数，在完成函数定义后、进行使用时给出列表。
unprinted_designs=['phone case', 'robot pendant', 'dedocahedron']
completed_models=[]

print_models(unprinted_designs, completed_models)
show_completed_models(completed_models)

print(unprinted_designs)

unprinted_models=['a','b','bb']
completed_models=[]
print_models(unprinted_models[:], completed_models)
show_completed_models(completed_models)

print(unprinted_models)
print(unprinted_models[:])

unprinted_models_designs=unprinted_models[:]#要是提供实参用后一半没用新的变量名，那新变量没有发生改变。
printed_models_designs=[]
print_models(unprinted_models_designs, printed_models_designs)
print(unprinted_models)
print(unprinted_models[:])
print(unprinted_models_designs)
#练习
#8-9消息
def show_messages(messages):
    """打印列表的信息"""
    for message in messages:
        print(message)
        
texts=['I hate being nervous about everything.',
      'I hate staying up late and get up late.',
      'I hate crying for something unnecessary.']
show_messages(texts)
#8-10发送消息
def send_messages(messages, sent_messages):
    """
    打印每条消息
    移动到sent_messages列表中
    """
    while messages:
        message=messages.pop()
        print(message)#打印变量对应内容别加引号变成打印变量名啦。
        sent_messages.append(message)
text=['I hate staying up and then getting up late.',
      'I hate spending night crying for something unnecessary.',
      'I hate being played like a fool.']
sent_text=[]
send_messages(text, sent_text)
print(text)
print(sent_text)
#8-11消息归档
def sen_messages(messages, sent_messages):
    """
    打印每条消息
    移动消息到sent_messages列表中"""
    while messages:
        message=messages.pop()
        print(message)
        sent_messages.append(message)

texts=['I hate being fooled again and again.',
      'I hate hear sorry without seeing any behavior again and over again.',
      'I hate being treated without any true heart.']
sent_texts=[]
send_messages(texts[:], sent_texts)   
print("")
print(texts)
print(sent_texts)    
#8.5传递任意数量的实参
def make_pizza(*toppings):
    """打印顾客点的所有配料"""
    print(toppings)#打印变量内容不是打印变量，别加引号！！！

make_pizza('pepperoni')
make_pizza('mushrooms', 'green peppers', 'extra cheese')

def make_pizza(*toppings):
    """打印顾客点的所有配料"""
    print("\nMaking a pizza with following toppings:")
    for topping in toppings:
        print(f"-{topping}")
        
make_pizza('pepperoni')
make_pizza('mushrooms', 'green pepper', 'more cheese')
#8.5.1传递任意数量的实参
def make_pizza(size,*toppings):
    """概述要制作的比萨"""
    print(f"\nMaking a {size}-inch pizza with following toppings:")
    for topping in toppings:
        print(f"-{topping}")
        
make_pizza(16, 'pepperoni')
make_pizza(12, 'mushrooms', 'green pepper', 'extra cheese')
#8.5.2使用任意数量的关键字实参
def build_profile(first, last, **user_info):
    """创建一个字典，其中包含我们知道的有关用户的一切。"""
    user_info['first name'] = first
    user_info['last name'] = last
    return user_info
user_profile=build_profile('albert', 'einstein', location='princeton', field='physics')
print(user_profile)
#练习
#8-12三明治
def sandwich_ingredients(*ingredients):
    print("\nThe sandwich consist of the following ingredients:")
    for ingredient in ingredients:
        print(f"-{ingredient}")

sandwich_ingredients('vegetables')
sandwich_ingredients('beef', 'vegetables', 'salad dressing')
sandwich_ingredients('ham', 'pork', 'lettuce')
#8-13用户简介
def build_profile(first, last, **user_info):
    """创建一个字典，其中包含我们知道的关于用户的一切。"""
    user_info['first name']=first
    user_info['last name']=last
    return user_info#别忘了返回啦！
someone_profile=build_profile('amanda', 'clarke', age=22, dream='revenge', lover='Aiden Mathius')#加引号是关键字参数了诶。
print(someone_profile)
#8-14汽车
def make_car(manufacturer, type, **car_info):
    """创建一个字典，包含一辆汽车的信息。"""
    car_info['manufacturer']=manufacturer
    car_info['type']=type
    return car_info

car = make_car('subaru', 'outback', color='bule', two_package=True)#函数用的是圆括号啊喂！！！
print(car)
#8.6将函数储存在模块中
#8.6.1导入整个模块
