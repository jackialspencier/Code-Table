favorite_languages={
    'jen':['python','ruby'],
    'sarah':['c'],
    'edward':['ruby','go'],
    'phil':['python','haskell'],
    }
for name,languages in favorite_languages.items():#记得.items()！！！
    print(f"{name.title()}'s favorite languages are:")
    
    for language in languages:
        print(f"\t{language.title()}")
#在字典中储存字典
users={
    'aeinstein':{
        'first_name':'albert',
        'second_name':'aeinstein',
        'location':'princeton',
        },
    'mcurie':{
        'first_name':'marie',
        'second_name':'mcurie',
        'location':'paris'
        },
    }
for username, user_info in users.items():
    print("\n"+username.title()+":")
    #for key, info in user_info.items():看看你这句有必要吗？搞得循环了三次。w焯，那不是和for alien_number in range(30)一样，以一个不会用于输出的变量增加/控制循环！！！啊啊啊好神奇！！！w爱了啊芜湖！！！！！!!!
    print(f"Full name: {user_info['first_name'].title()} {user_info['second_name'].title()}")
    print(f"Location: {user_info['location'].title()}")

users={
    'aeinstein':{
        'first':'albert',
        'second':'aeinstein',
        'location':'princeton',
        },
    'mcurie':{
        'first':'marie',
        'second':'mcurie',
        'location':'paris',
        }
    }
for username, user_info in users.items():
    print(f"\nUsername:{username}")
    
    full_name=f"{user_info['first'].title()} {user_info['second'].title()}"
    location=user_info['location'].title()
    print(f"\tFullname: {full_name}")
    print(f"\tLocation: {location}")
#练习
#6-7人们
men=[]
man_1={
    'first name':'eliot',
    'second name':'spencer',
    'age':'29',
    'city':'new york'
    }
man_2={
    'first name':'amanda',
    'second name':'clarke',
    'age':'23',
    'city':'hampton',
    }
man_3={
    'first name':'aiden',
    'second name':'mathius',
    'age':'24',
    'city':'hanmpton',
    }
men.append(man_1)
men.append(man_2)
men.append(man_3)#有什么别的实现方法吗

for man in men:
    print("\t")
    for key, value in man.items():
        print(key.title()+":\n\t"+value.title())
        
for man in men:
    full_name=f"{man['first name'].title()} {man['second name'].title()}"
    print(f"\n{full_name}")
    print(f"\tAge:{man['age']}\n\tCity:{man['city'].title()}")    
    #Full_name=f"info['first_name']"

for man in men:
    print(man) 
#6-8宠物
pet_1={
    'type':'dog',
    'master':'amanda',
    }
pet_2={
    'type':'cat',
    'master':'danniel',
    }
pet_3={
    'type':'snake',
    'master':'norlan',
    }
pets=[pet_1,pet_2,pet_3]
for pet in pets:
    print(pet)
#对字典列表进行遍历时如果需要将内容进行组织，对于内容的使用方法是字典名加索引(只要值)，另加循环（不能针对某个特定变量，一直在变）适用于组织了格式但并未组织过多内容。
#6-9喜欢的地方
favorite_places={
    'amanda':['hampton','china'],
    'sophine':['paris','new york','london'],
    'patrick':['paris'],
    }
for name, places in favorite_places.items():#单纯抽离访问字典的模式
#嵌套的访问方式其实是由外向内应用该层抽离来看作为字典/列表的访问方式。
    if len(places)==1:
        print(f"{name.title()}'s favorite place is:")
    else:
        print(f"{name.title()}'s favorite places are:")
    for place in places:
        print(f"\t{place.title()}")
#由框架到细节
#6-10喜欢的数2
favorite_numbers={
    'jim':[10,12,18],
    'amanda':[8,88],
    'norlan':[7,21,3,5],
    'aiden':[19,3,26.24],
    'chandler':[2,8,9,13,16]
    }
for name, numbers in favorite_numbers.items():
    print(f"{name.title()}'s favorite numbers are:")
    for number in numbers:
        print(f"\t{number}")
#6-11城市
cities={
    'hampton':{
        'country':'America',
        'population':'1.3million',
        'fact':'Revenge',
        },
    'beijing':{
        'country':'China',
        'population':'21.9million',
        'fact':'It is the capital of China.'
        },
    'shanghai':{
        'country':'China',
        'population':'24.8million',
        'fact':'It is developing quickly, especially in the field of economy.',
        },
    }
for city, info in cities.items():
    print(f"\n{city.title()}:")
    for key, information in info.items():
        print(f"\t{key.title()}:{information}")#如果国家处需要小写转大写而事实保持仅整句首字母大写呢?那就只能用索引了？那如果前面信息很多呢？字典有没有切片的类似功能呢？或者设置if key=='fact'和else以进行区分，对特殊元素（？）进行处理。
#6-12拓展（可以算见练习6-7多种输出方式？）