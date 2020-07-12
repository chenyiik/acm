def inv(n):
    if n==1 or n==0:
        return 1
    return ((998244353-(998244353//n))*inv(998244353%n))%998244353
frac=[0 for _ in range(int(2e6+51))]
frac[0]=1
for i in range(1,int(2e6+51)):
    frac[i]=(frac[i-1]*i)%998244353
while 1:
    try:
        n=int(input())
        print((frac[n]**2)*inv(frac[2*n+1])%998244353)
    except:
        break