import math
f=[0,1]
n,m=map(int,input().split())
for i in range(2,n+1):
	f.append(f[i-1]+f[i-2])
ans=0
for i in range(n+1):
	ans=ans+int(math.pow(f[i],m))
print(ans)
