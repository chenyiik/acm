n,s=map(int,input().strip().split())
bet=dict()
for i in range(n):
    t,b=input().strip().split()
    b=int(b)
    bet[t]=b
bets=sorted(bet.items(),key=lambda x:x[1],reverse=True)
ans=[]
for x in bets:
    if (x[1]<=s):
        s-=x[1]
        ans.append(x[0])
if s!=0:
    print(0)
    exit(0)
print(len(ans))
for x in ans:
    print(x)
