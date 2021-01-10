t=int(input())
for tt in range(t):
    n=int(input())
    ans=[]
    flag=set()
    ok=True
    x=1
    flag.add(x)
    ans.append(x)
    for i in range(n-2):
        if not 2*x%n in flag:
            x=x*2%n
        elif not 3*x%n in flag:
            x=x*3%n
        else:
            ok=False
            print(-1)
            break
        flag.add(x)
        ans.append(x)
    if ok:
        print(' '.join(map(str,ans)))