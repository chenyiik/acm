def f(x):
    dans=1
    vsf=1
    for i in range(len(str(x))):
        vsf*=10
        dans*=(x%vsf)
    dans%=x+1
    return dans
def doo(n,m):
    las=f(n)
    res=f(n)
    tx=0
    for i in range(2,m+1):
        now=f(las)
        res+=now
        if now==las:
            tx=i
            break
        las=now
    if tx!=0:
        res+=(m-i)*las
    return res
if __name__=="__main__":
    t=int(input())
    for kt in range(t):
        n,m=map(int,input().strip().split())
        print(doo(n,m))