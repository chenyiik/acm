l,m=map(int,input().strip().split())
jqr=[]
for i in range(m):
    n,p,c,t,r=input().strip().split(sep=",")
    p,c,t,r=map(int,[p,c,t,r])
    aw=c*t
    ti=l/aw*(t+r)
    if ti<=10080:
        jqr.append([n,p,c,t,r])
if len(jqr)==0:
    print("no such mower")
    exit(0)
jqrs=sorted(jqr,key=lambda x:x[1])
mp=jqrs[0][1]
for x in jqrs:
    if x[1]==mp:
        print(x[0])
    else:
        break
