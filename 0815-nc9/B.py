import math
T=int(input())
for _ in range(T):
	bj=0
	b,c=map(int,input().split())
	for i in range(1,int(1e9+7)//2+1):
		x=i
		y=int(1e9+7)+b-x
		y%=int(1e9+7)
		if x*y%int(1e9+7)==c:
			bj=1
			print(x,y)
			break

	if bj==0:
		print(-1)

