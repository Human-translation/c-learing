import random
num = random.random()
print(num*100//1)

x = -1

while x != num:
    x = input("请输入一个数:")
    x = int(x)
    if x > num:
        print("输入过大")
    elif x < num:
        print("输入过小")
    else:
        print("答对了(￣▽￣)~*")

#random.randint(0,100) 返回整数
#random.random() 返回0-1小数
#type(x) 查看类型
#isinstance(x,int) 类型是否匹配