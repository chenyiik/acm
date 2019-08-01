def multi(a,b,p):
	c=(((a[0][0]*b[0][0]+a[0][1]*b[1][0])%p,(a[0][0]*b[0][1]+a[0][1]*b[1][1])%p),((a[1][0]*b[0][0]+a[1][1]*b[1][0])%p,(a[1][0]*b[0][1]+a[1][1]*b[1][1])%p))
	return c
def quick(x,a,p):
	res=((1,0),(0,1))
	while(a>0):
		if(a&1):
			res=multi(x,res,p)
		a>>=1
		x=multi(x,x,p)
	return res
x0,x1,b,a=map(int,input("").split())
n,p=map(int,input("").split())
ans=quick(((0,a),(1,b)),n-1,p)
print((x0*ans[0][1]+x1*ans[1][1])%p)
