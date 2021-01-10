n,k=map(int,input().split())
if n%2==0 and k==n//2:
    for x in range(1,n//2):
        print(x,n-x,end=' ')
    print(n//2,n)
    exit(0)
if n%2==1 and k==0:
    for x in range(1,1+(n//2)):
        print(x,n-x,end=' ')
    print(n)
    exit(0)
print(-1)