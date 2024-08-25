#5.1一个简单示例
cars = ['audi','bmw','subaru','toyota']
#自行尝试
for car in cars:
    if car is 'bmw':
        print(car.upper())
    else:
        print(car.title())
#跟书练习：
for car in cars:
    if car == 'bmw':
        print(car.upper())
    else:
        print(car.title())
        
               
#5.2条件测试
#5.2.1检查是否相等
#5.2.2检查是否相等时忽略大小
#5.2.3检查是否不相等
requested_topping = 'mushrooms'
if requested_topping != 'anchovies':
    print("Hold the anchovies!")#相等就算了，不相等马上执行警告！！！
#5.2.4数值比较  
answer = 17
if answer != 42:
    print("That is not the correct answer. Please try again!")
#5.2.5检查多个条件
#5.2.6检查特定值是否普包含在列表中
#5.2.7检查特点值是否不包含在列表中
banned_users = ['carolina','david','andrew']
user = 'marie'
if user not in banned_users:
    print(f"{user.title()},you can post a message if you wish.")
#练习
#5-1（一）
car = 'saburu'
print("\nIs car == 'saburu'? I predict True.")
print(car == 'saburu')

print("is car == 'audi'? I predict False.")
print(car == 'audi')

price = 100
print("\nIs price == 100? I predict True.")
print(price == 100)

print("Is price == 111? I predict False.")
print(price == 111)

comment = "The peach is not so sweat."
print("\nIs comment == 'The peach is not so sweat.'? I predict True.")
print(comment == "The peach is not so sweat.")

print("Is comment == 'The peach is sweat.'? I predict False.")
print(comment == 'The peach is sweat.')

pizza = 'spicy'
print("\nIs pizza == 'spicy'? I predict True.")
print(pizza == 'spicy')

print("Is pizza == 'salty'? I predict False.")
print(pizza == 'salty')

school = 'junior high school'
print("\nIs school == 'junior high school'? I predict True.")
print(school == 'junior high school')

print("Is school == 'university'? I predict False.")
print(school == 'university')

temperature = 30
print("\nIs temperature == 30? I predict True.")
print(temperature == 30)

print("Is temperature == 35? I predict False.")
print(temperature == 35)

state = 'awake'
print("\nIs atate == 'awake'? I predict True.")
print(state == 'awake')

print("Is state == 'sleepy'? I predict Falde.")
print(state == 'sleepy')

time = "5:13"
print("\nIs time == '5:13'? I predict True.")
print(time == '5:13')

print("Is time == '17:13'? I predict False.")
print(time == "17:13")

mood = 'worried'
print("\nIs mood == 'worried'? I predict True.")
print(mood == 'worried')

print("Is mood == 'happy'? I predict False.")
print(mood == 'happy')

sky = 'bright'
print("\nIs sky == 'bright'? I predict True.")
print(sky == 'bright')

print("Is sky=='dark'? I predict False.")
print(sky == 'dark')

#5-2(二)conditional_tests.py
coffee1 = 'timo'
coffee2 = 'lucky'
coffee3 = 'timo'
print('\n')
print(coffee1 == coffee2)
print(coffee1 == coffee3)

name1 = 'Lucy'
name2 = 'Norlan'
#nmae3="lucy"
print(name1 == "lucy")
print(name2 == 'lucy')
print(name1.lower() == 'lucy')
print(name2.lower() == 'lucy')
print("Lucy" == 'lucy')
print('Lucy'.lower() == 'lucy')

number1 = 100
number2 = 120
print("\n")
print(100 < 100)
print(120 < 110)
print(number1 <= 110)
print(number2 <= 110)
print(number1 == 100)
print(number2 == 100)
print(number1 != 120)
print(number2 != 120)
print(number1 > 90)
print(number2 > 120)
print(number1 >= 110)
print(number2 >= 130)

print("\n")
time = "5:33"
mood = "concerned"
print(time == "5:13" and mood == "concerned")
print(time == "5:33" and mood == "concerned")
print(time == "5:13" or mood == "happy")
print(time == "5:13" or mood == "concerned")

moods = ['low','unhappy','nervous','concerned','worried']
mood1 = 'nervous'
mood2 = 'excited'
print(mood1 in moods)
print(mood2 in moods)
mood3 = "well-being"
mood4 = 'unhappy'
print(mood3 not in moods)
print(mood4 not in moods)


#5.3if语句
#5.3.1简单的if语句
age = 19#19是数字，不是字符串不需要加‘’或“”，故不是“19”否则无法比较
if age >= 18:
    print("You are old enough to vote!")
    print("Have you registered to vote yet?")
#5.3.2if-else语句
age = 17
if age >= 18:
    print("You are old enough to vote!")
    print("Have you registered to vote yet?")
else:
    print("Sorry, you are too young to vote.")
    print("Please register to vote as soon as you turn 18!")

age = 12
#if age>-
if age < 4:#看书上发现可以有空格。原“if age<4:”.。
    print("Free.")
elif age >= 4 and age < 18:#这里用if好像也可以？！
    print("25 dollars.")
else:
    print("40 dollars.")

age = 12
if age < 4:
    print("Your admission cost is $0.")
elif age < 18:
    print("Your admission cost is $25.")
else:
    print('Your admission cost is $40.')
    
age = 12
#空一行易读。
if age < 4:
    price = 0
elif age < 18:
    price = 25
else:
    price = 40
#空一行易读。
print(f"Your admission cost is ${price}.")

age = 12

if age < 4:
    price = 0
elif age < 18:
    price=   25#诶，可以这样空的嘛。
elif age < 65:
    price = 40
else:
    price = 20
    
print(f"Your admission price is ${price}.")

age = 12

if age < 4:
    price = 0
elif age < 18:
    price = 25
elif age < 65:
    price = 40
elif age >= 65:
    price = 20

print(f"Your admission cost is ${price}.")

requested_toppings = ['mushrooms','extra cheese']
#空一行易读。
if 'mushrooms' in requested_toppings:
    print("Adding mushrooms.")
if 'pepperoni' in requested_toppings:
    print("Adding pepperoni.")
if 'extra cheese' in requested_toppings:
    print("Adding extra cheese.")
    
print("\nFinished making your pizza!")

requested_toppings = ['mushrooms','extra cheese']
if 'mushrooms' in requested_toppings:#别列表里'mushroom',条件里'mushrooms'.。
    print("Adding mushrroms.")
elif 'pepperoni' in requested_toppings:
    print("Adding pepperoni.")
elif 'extea cheese' in requested_toppings:
    print("Adding extra cheese.")
    
print("\nFinished making your pizza!")

#练习
#5-3（一）
alien_color = 'green'
if alien_color == "green":#区分==和=
    print("Your have gained 5 points.")

if alien_color == 'green':
    print("You have gained 6 points.")
    
if alien_color == 'red':#区分==和=。
    print("YOu have gained 6 points.")
#5-4(二)   
alien_color = 'yellow'

if alien_color == 'green':
    print("You have gained 5 points for shooting the green alien.")
else:
    print("You have gained 10 points.")
    
alien_color = 'green'
 
if alien_color == 'green':
    point = 5   
else:
    point = 10

print(f'You have gained {point} points.')
#5-5（三）
alien_color = 'green'
if alien_color == 'green':
    print("\nYou have gained 5 points")#此处\n是出于易读考虑自加。
elif alien_color == 'yellow':
    print("You have gained 10 points.")
elif alien_color == 'red':
    print("You have gained 15 points.")

alien_color = 'yellow'
if alien_color == 'green':
    print("You have gained 5 points.")
elif alien_color == 'yellow':
    print("You have gained 10 points.") 
elif alien_color == 'red':
    print("You have gained 15 points.")

alien_color = 'red'
if alien_color == 'green':
    print("You have gained 5 points.")
elif alien_color == 'yellow':
    print("You have gained 10 points.")
elif alien_color == 'red':
    print("You have gained 15 points.")
    
#5-6（四）
age=18
if age < 2:
    print("The person is a baby.")#婴儿infant，baby
elif age < 4:
    print("The person is a young baby.")#toddler？？
elif age < 13:
    print("The person is a child.")
elif age < 20:
    print("The person is a teenager.")
elif age < 65:
    print("The person is an adult")
else:
    print("The person is an old man.")
    
#5-7(五)
fruits = ['apples','watermelons','oranges']
if 'apples' in fruits:
    print("You really like apples!")
if 'bananas' in fruits:
    print("You really like bananas!")
if 'grapes' in fruits:
    print("You really like grapes!")
if 'oranges' in fruits:
    print("You really like oranges!")
if 'watermelons'in fruits:
    print("You really like watermelons!")
    
requested_toppings = ['mushrooms','green peppers','extra cheese']
for requested_topping in requested_toppings:
    print(f"Adding {requested_topping}")   
print("\nFinished making your pizza!")

requested_toppings = ['mushrooms','green peppers','extra_cheese']
for requested_topping in requested_toppings:
    if requested_topping == 'green peppers':
        print("Sorry, we are out of green peppers right now.")
    else:
        print(f"Adding {requested_topping}.")
print("\nFinished making your pizza!")  
#5.4.2确定列表不是空的。
requested_toppings = []
if requested_toppings:
    for requested_topping in requested_toppings:
        print(f"Adding {requested_topping}.")
    print("\nFinished making your pizza!")
else:
    print("Are you sure you want a plain pizza?")
#5.4.3
available_toppings = ['mushrooms','olives','green peppers','pepperoni','pineapple'
                    ,'extra cheese']
requested_toppings = ['mushrooms','french fries','extra cheese']
for requested_topping in requested_toppings:
    #if requested_topping in requested_toppings:(注意明确什么时候用哪张表。)
    if requested_topping in available_toppings: 
        print(f"Adding {requested_topping}.")
    else:
        #print(f"Sorry, {requested_topping} is not available.")
        print(f"Sorry, we don't have {requested_topping}.")
print("\nFinished making your pizza!")
#练习
#5-8（一）
names = ['admin','hardison','amanda','emily','norlan']
for name in names:
    if name == 'admin':
        print("Hello admin, would you like to see a status report?")
    else:
        print(f"Hello {name.title()}, thank you for logging in again.")
#5-9(二)
names = []
if names:
    for name in names:
        if name == 'admin':
            print("Hello admin, would you like to see a status report?")
        else:
            print(f"Hello {name.title()}, thank you for logging again.")#注意调用变量的值别忘了f!!
else:
    print("We need to find some users!")
#5-10(三)!!!注意。
current_users = ['Spencer','Hardison','Parker','Nate','Sophine']
current_users2 = []
for user in current_users:
    current_users2.append(user.lower())
new_users = ['NATE','Sophine','Amanda','Norlan','Aiden']
for new_user in new_users:
    if new_user.lower() in current_users2:
        print(f"The name {new_user} has been used. Please take another name.")
    else:
        print(f"The name {new_user} hasn't been used.")
print(current_users2)

numbers = list(range(1,10))
for number in numbers:
    if number == 1:
        print("\n1st")
    elif number == 2:
        print("2nd")
    elif number == 3:
        print("rd")#无需\n,每次就独占一行。\n对应多空一行。
    else:
        print(f"{number}th")
    

    