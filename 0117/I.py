spec=0
def f(n,s,by,t):
    global spec
    if n==1:
        if spec==0:
            print(f"{s} {t}")
        else:
            print(f"{s} {by}\n{by} {t}")
            spec=0
        return
    f(n-1,s,t,by)
    print(f"{s} {t}")
    f(n-1,by,s,t)
if __name__=="__main__":
    n,m=map(int,input().split())
    lim=(1<<n)-1
    if m<lim:
        print("N")
        exit(0)
    print("Y")
    while m-2>=lim:
        print("A B\nB A")
        m-=2
    if m==lim+1:
        spec=1
    f(n,"A","B","C")
