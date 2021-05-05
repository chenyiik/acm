n=int(input())
x=list(map(int,input().split()))
x=list(zip(x,[i for i in range(len(x))]))
for i in range(len(x)):
    x[i]=list(x[i])
round=0
while round<1e18:
    round+=1
    i,wf,of=0,len(x),0
    while i<wf:
        x[i][0]-=(i+1)
        if x[i][0]<=0:
            print(x[i][1]+1,end=" ")
            x=x[:i]+x[i+1:]
            wf-=1
        else:
            i+=1
    if wf==0:
        break
