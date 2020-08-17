a,b,c,n=map(int,input().split())
mag=3
if a!=b and b!=c and a!=c:
    mag=6
if a==b and b==c and a==b:
    mag=1
modl=2**64
ans=0
if n%2==0:
    ans=n*(n-2)*(n+8)
else:
    ans=n*(n+1)*(n-1)
ans//=24
ans*=mag
ans%=modl
print(ans)