num = 1

for i in range(num):
    if i%2:
        print(i,end=' ')


def paiming(num):
    if num > 90:
        print("A")
    elif num > 80:
        print("B")
    elif num >70:
        print("C")
    elif num > 60:
        print("D")

paiming(75)

x=10
y=20
z=30
small = x if (x < y and x < z) else (y if y < z else z)


def fun():
    count = 3
    password = "nihao"
    while count:
        str = input()
        if str == password:
            print("true")
            break
        if "*" in str:
            print("No")
            continue
        else:
            print("False")
        count -= 1

def fun2():
    for number in range(100,1000):
        baiwei = number // 100
        shiwei = number % 100 // 10
        gewei = number % 10
        if baiwei ** 3 + shiwei ** 3 + gewei ** 3 == number:
            print(number,end=" ")



for red in range(0, 4):
    for yellow in range(0, 4):
        for green in range(2, 7):
            if red + yellow + green == 8:
                # 注意，下边不是字符串拼接，因此不用“+”哦~
                print(red, '\t', yellow, '\t', green)


opt(1) = max(opt(0) , opt(5)+val)

dev
1     4   1   1   9    1

arr[n] = max(arr[n-2]+ val,arr[n-1])

arr[0] = dev[0]
arr[1] = max(dev[0],dev[1])

arr[2] = max(arr[0]+dev[2],arr[1])