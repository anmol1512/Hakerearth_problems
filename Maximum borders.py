import re
t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    t=''
    on_off=0
    count=0
    for i in range(n):
        s=input()
        ob1=re.search('#+',s)
        if ob1!=None:
            x=set(range(ob1.start(),ob1.end()))
        else:
            if bool(t):
                ob2=re.search('#+',t)
                if len(t[ob2.start():ob2.end()])>count:
                    count=len(t[ob2.start():ob2.end()])
                t=''
            continue
        if bool(t):
            ob2=re.search('#+',t)
            y=set(range(ob2.start(),ob2.end()))
            if bool(x.intersection(y)):
                if on_off==1:
                    if len(t[ob2.start():ob2.end()])>count:
                        count=len(t[ob2.start():ob2.end()])
                        on_off=0
                t=s
                if i==n-1:
                    if len(t[ob1.start():ob1.end()])>count:
                        count=len(t[ob1.start():ob1.end()])
            else:
                if len(t[ob2.start():ob2.end()])>count:
                    count=len(t[ob2.start():ob2.end()])
                t=s 
                on_off=1
        else:
            t=s
            on_off=1
            if n==1:
                if on_off==1:
                    count=len(s[ob1.start():ob1.end()])

    print(count)

