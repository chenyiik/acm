import math
n,m=map(int,input().split())
ans=0
for k in range(1,n+1):
	ans=ans+((k*m)&m)%(int(1e9+7))
print(ans)

