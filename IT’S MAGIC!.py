n=int(input())
arr=[int(x) for x in input().split()]
min_no=None
s=sum(arr)
for i in range(n):
    x=s-arr[i]
    if x%7==0:
        if min_no==None:
            min_no=arr[i]
        if min_no>arr[i]:
            min_no=arr[i]

if min_no==None:
    print(-1)
else:
    print(arr.index(min_no))