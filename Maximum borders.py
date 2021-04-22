import re
t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    shape=[];test=None;maxb=[];first=1
    for j in range(n):
        r=str(input())
        find=re.search('#+',r)
        if find:
            if first:
                shape.append(r[find.start():find.end()])
                test=find
                first=0
            else:
                if '#' in r[test.start():test.end()]:
                    shape.append(r[find.start():find.end()])
                    test=find
                else:
                    maxb.append(len(shape[0]))
                    maxb.append(len(shape[-1]))
                    shape.clear()
                    shape.append(r[find.start():find.end()])
                    test=find
        else:
            if shape:
                maxb.append(len(shape[0]))
                maxb.append(len(shape[-1]))
                shape.clear()
            first=1
    else:
        if shape:
            maxb.append(len(shape[0]))
            maxb.append(len(shape[-1]))
    print(max(maxb))