def gcd(a,b):
    if a%b==0:
        return b
    return gcd(b,a%b)
a=[]
vis=[]
cir=[]
def dfs(x,len):
    global a,vis,cir
    if vis[x]:
        cir.append(len)
        return
    vis[x]=True
    dfs(a[x],len+1)
def solve(x,len):
    global a,vis,cir
    cur=x
    while not vis[x]:
        len+=1
        vis[x]=True
        x=a[x]
    cir.append(len)
n=int(input())
a=input().split()
vis=[False for i in range(n)]
for i in range(n):
    a[i]=int(a[i])-1
for i in range(n):
    if not vis[i]:
        solve(i,0)
res=cir[0]
for i in range(1,len(cir)):
    res=res*(cir[i]//gcd(res,cir[i]))
print(res%(10**n))
