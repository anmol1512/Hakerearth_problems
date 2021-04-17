import re
t= int(input())
for i in range(t):
    n=int(input())
    s=str(input())
    l=re.findall('.[a|e|i|o|u]',s)
    fl=[x for x in l if x[0] not in ['a','e','i','o','u']]
    print(len(fl))