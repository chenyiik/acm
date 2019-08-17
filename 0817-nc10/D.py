def gcd(x,y):
    if y==0:
        return x
    return gcd(y,x%y)
def exgcd(a,b,x,y):
    #print(a,b,x,y)
    if b==0:
        x[0]=1
        y[0]=0
        return a
    r=exgcd(b,a%b,x,y)
    t=x[0]
    x[0]=y[0]
    y[0]=t-(a//b)*y[0]
    return r
def crt(a,m,n):
    aa=a[0]
    mm=m[0]
    x=[0]
    y=[0]
    for i in range(1,n):
        d=exgcd(mm,m[i],x,y)
        c=a[i]-aa
        if c%d:
            return -1
        mul=m[i]//d
        x[0]=(c//d*x[0]%mul+mul)%mul
        aa=aa+mm*x[0]
        mm=mm*mul
        aa%=mm
    return (aa+mm)%mm
dep=0
m=[]
a=[]
n,mn=map(int,input().split())
for i in range(n):
    m1,a1=map(int,input().split())
    m.append(m1)
    a.append(a1)
ans=crt(a,m,n)
if ans<0:
    print("he was definitely lying")
elif ans>mn:
    print("he was probably lying")
else:
    print(ans)