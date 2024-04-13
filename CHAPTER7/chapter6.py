#6.1一个简单的字典
alien_0={'color':'green','points':5}
print(alien_0['color'])
print(alien_0['points'])
#6.2使用字典
alien_0={'color':'green','points':5}
#6.2.1访问字典中的值
alien_0={'color':'green'}
print(alien_0['color'])
alien_0={'color':'green','points':5}
new_points=alien_0['points']
print(f"You just earned {new_points} points!")
#6.2.2添加键值对
alien_0 = {'color':'green','points':5}
print(alien_0)
alien_0['x_position'] = 0
alien_0['y_position'] = 25
print(alien_0)
#6.2.3先创建一个空字典
alien_0={}
alien_0['color'] = 'green'
alien_0['points'] = 5
print(alien_0)
#6.2.4修改字典中的值
alien_0={'color':'green'}
print(f"The alien is {alien_0['color']}.")#别忘了花括号。
alien_0['color']='yellow'
print(f"The alien is now {alien_0['color']}.")#别忘了花括号。

alien_0={'x_position':0,'y_position':0,'speed':'medium'}
print(f"Original position: {alien_0['x_position']}")
#if alien_0['speed']:'slow':
if alien_0['speed']=='slow':
    x_increment=1
elif alien_0['speed']=='medium':
    x_increment=2
else:
    x_increment=3
alien_0['x_position']=alien_0['x_position'] + x_increment
print(f"New position:{alien_0['x_position']}")
#6.2.5删除键值对
alien_0 = {'color':'green','points':5}
print(alien_0)
del alien_0['points']
print(alien_0)
#6.2.6由类似对象组成的字典
favorite_languages={
    'jen':'python',
    'sarah':'c',
    'edward':'ruby',
    'phil':'python',
    }
language = favorite_languages['sarah'].title()
print(f"Sarah's favorite language is {language}.")
#6.2.7使用get来访问值
#alien_0={'color':'green','speed':'medium'}
#print(alien_0['points'])

alien_0={'color':'green','speed':'medium'}
point_value=alien_0.get('points','No point value assigned.')
print(point_value)
x_position=alien_0.get('x_position')#此后的逗号可加可不加。
print(x_position)
#练习
#6-1(一)
information={'first_name':'ross','last_name':'norlan','age':28,'city':'hampton'}
print(information['first_name'].title())
print(information['last_name'].title())
print(information['age'])
print(information['city'].title())
#6-2（二）
favorite_numbers={
    'norlan':21,
    'amanda':88,
    'parker':6,
    'nate':13,
    'aiden':16
    }
names=['norlan','amanda','parker','nate','aiden']
for name in names:
    favorite_number=favorite_numbers[name]
    print(f"{name.title()}'s favorite number is {favorite_number}.")
favorite_number1=favorite_numbers['norlan']
print(f"Norlan's favorite number is {favorite_number1}.")
favorite_number2=favorite_numbers['amanda']
print(f"Amanda's favorite number is {favorite_number2}.")
favorite_number3=favorite_numbers['parker']
print(f"Parker's favorite number is {favorite_number3}.")
favorite_number4=favorite_numbers['nate']
print(f"Nate's favorite number is {favorite_number4}.")
favorite_number5=favorite_numbers['aiden']
print(f"Aiden's favorite number is {favorite_number5}.")
words={'print':'打印','lower':'小写','upper':'大写','pop':'弹出','append':'添加'}
print(f"print: {words['print']}")#这里需要花括号哦~。
print(f"lower: {words['lower']}")#这里也需要花括号哦~。
print(f"upper: {words['upper']}")
print(f"pop: {words['pop']}")
print(f"append: {words['append']}")
professions=['print','lower','upper','pop','append']
for profession in professions:
    print(profession)
    print(f"\n    {words[profession]}")
#6.3遍历字典
#6.3.1遍历所有键值对
user_0={
    'username':'eferi',
    'first':'enrico',
    'last':'fermi'
    }
for key, value in user_0.items():
    print(f"\nKey:{key}")
    print(f"Value:{value}")
#for k,v in user_0.

favorite_language={
    'jen':'python',
    'sarah':'c',
    'edward':'ruby',
    'phil':'python'
    }
#注意逗号！！！以及冒号，引号。
for name, language in favorite_language.items():
    print(f"{name.title()}'s favorite language is {language.title()}.")

#6.3.2遍历字典中的所有键
for name in favorite_language.keys():#冒号！！！
    print(name.title())
for name in favorite_languages:
    print(name)
print("")
#自行尝试
friends=['phil','sarah']
for name, language in favorite_languages.items():#注意此时.items()不可省略。
    print(f"Hi, {name.title()}.")
    if name in friends:
        print(f"\t{name.title()}, I see you love {language.title()}！")
#book
for name in favorite_language:
    print(f"Hi, {name.title()}.")
    if name in friends:
        language=favorite_languages[name]   
        print(f"\t{name.title()}, I see you love {language.title()}!") 
#对于值的提取有两种方法，一是.items()提取列表，适合提取所有的值。二则在完成键的遍历后利用键以访问的方式提取特定的值。
#6.3.3按特定顺序遍历字典中的所有键
favorite_languages={
    'jen':'python',
    'sarah':'c',
    'edward':"ruby",
    'phil':'python'
    }
for name in sorted(favorite_languages.keys()):
    print(f"{name.title()}, thank you for taking the poll.")
    
print("The following languages have been mentioned:")
for language in favorite_languages.values():
    #print(f"{language.title()}")
    print(language.title())#仅访问变量而不是同时访问变量和字符串可以直接输入变量名，不需要引号，不需要花括号。

print("The following languages have been mentioned:")
for language in set(favorite_language.values()):
    print(language.title())
#练习
#6-4
words={'print':'打印','append':'添加','insert':'插入','del':'删除','pop':'弹出'}
for word,meaning in words.items():
    print(f"{word}:{meaning}")
    

words={'print':'打印','append':'添加','insert':'插入','del':'删除','pop':'弹出','set':'集合','list':'列表','range':'范围','upper':'大写','lower':'小写'}
for word,meaning in words.items():
    print(word)
    print(f"\n\t{meaning}")#不能（print("\n\t"meaning)）
#6-5
geography={'nile':'egypt','yangtze river':'china','yellow river':'china'}
for river, country in geography.items():
    print(f"The {river.title()} runs through {country.title()}.")
for river in geography.keys():
    print(river.title())
for country in geography.values():
    print(country.title())
#6-6
favorite_languages={
    'jen':'python',
    'sarah':'c',
    'edward':'ruby',
    'phil':'python'
    }
men_supposed=['jen','sarah','edward','phil','parker','hardison','nate','sophine','eliot']
for man in men_supposed:
    if man in favorite_languages.keys():#注意区分预备使用的列表，字典等的名字！区分！
        print(f"{man.title()}, thank you for your engagement in the investigation!")
    else:
        print(f"I sincerely invite you to take the test, {man.title()}.")
#6.4嵌套
#6.4.1字典列表
alien_0={'color':'green','points':5}
alien_1={'color':'yellow','points':10}
alien_2={'color':'red','points':15}
aliens=[alien_0, alien_1, alien_2]
for alien in aliens:
    print(alien)

aliens=[]
for alien_number in range(30):
    new_alien={'color':'green','points':5,'speed':'slow'}
    aliens.append(new_alien)

for alien in aliens[:5]:
    print(alien)
print("...")
#自行尝试修改
print(f"The total length of aliens is {len(alien)}.")
for alien in aliens[:3]:
    alien={'color':'yellow','points':10,'speed':'slow'}
    print(alien)

aliens=[]
for alien_number in range(30):
    new_alien={'color':'green','points':5,'speed':'slow'}
    aliens.append(new_alien)
for alien in aliens[:3]:
    if alien['color']=='green':#注意这里用==
        alien['color']='yellow'
        alien['points']=10
        alien['apeed']='medium'

for alien in aliens[:3]:
    print(alien)
    
aliens=[]
for alien_number in range(30):
    new_alien={'color':'green','points':5,'speed':'slow'}
    #明确正在输入/创建的是列表还是字典，确定中括号or花括号。
    aliens.append(new_alien)
for alien in aliens[:3]:
    if alien['color']=='green':
        alien['color']='yellow'
        alien['points']=10
        alien['speed']='medium'
    elif alien['color']=='yellow':
        alien['color']='red'
        alien['points']=10
        alien['speed']='fast'
for alien in aliens[:3]:
    print(alien)
#懵逼
#6.4.2在字典中储存列表
pizza={
    'crust':'thick',
    'toppings':['mushirooms','extra_cheese']
    }
print(f"You ordered a {pizza['crust']}-crust pizza with the following toppings:")
for topping in pizza['toppings']:
    print(f"\t{topping}")

pizza={
    'crust':'thick',
    'toppings':['mushrooms','extra cheese']
    }
print(f"You ordered a {pizza['crust']}-crust pizza with following toppings:")
for topping in pizza['toppings']:
    print("\t"+topping)
#关注一下这里加号连接字符串的作用

favorite_languages={
    'jen':['python','ruby'],
    'sarah':['c'],
    'edward':['ruby','go'],
    'phil':['python','haskell'],
    }
for name,languages in favorite_languages.items():#记得.items()！！！
    print(f"{name.title()}'s favorite languages are:")
    print(languages)
    for langauge in languages:
        print(f"\t{language.title()}")



       
    

            
    
