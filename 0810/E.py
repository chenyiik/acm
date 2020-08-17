t=int(input())
while t:
    t-=1
    n=int(input())
    ans,now,res=0,0,0
    tx=list(map(int,input().split()))
    for i in range(1,n+1):
        x=tx[i-1]
        now+=x
        r=now//i+(now%i>0)
        ans=max(ans,r)
    print(ans)