t1=input().split(':')
t2=input().split(':')
t1=list(map(int,t1))
t2=list(map(int,t2))
if t1[0]>t2[0]:
    t2,t1=t1,t2
elif t1[0]==t2[0] and t1[1]>t2[1]:
    t2,t1=t1,t2
elif t1[0]==t2[0] and t1[1]==t2[1] and t1[2]>t2[2]:
    t2,t1=t1,t2
ans=(t2[0]-t1[0])*3600+(t2[1]-t1[1])*60+t2[2]-t1[2]
print(ans)