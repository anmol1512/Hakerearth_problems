t=int(input())
for i in range(t):
    x,y,a,b=[int(t) for t in input().split()]
    if x*y==a+b:
        print('Yes')
    else:
        print('No')