t=int(input())
for i in range(t):
    a,b,c=map(int,input().split())
    if (a+c)%2==0:
        x=(a+c)//2
        print(abs(x-b))
    else:
        import math
        x=(a+c)/2
        if b>x:
            x=math.floor(x)
            print(b-x)
        else:
            x=math.ceil(x)
            print(x-b)
