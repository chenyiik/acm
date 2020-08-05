def solve():
    n=int(input())
    if (n<3):
        for i in range(n):
            t=input()
        return "-1"
    cards=[]
    for i in range(n):
        va=input().split('][')
        va[0]=va[0][1:]
        va[3]=va[3][:-1]
        cards.append(va)
    #cards=sorted(cards)
    for i in range(len(cards)-2):
        for j in range(i+1,len(cards)-1):
            for k in range(j+1,len(cards)):
                ok=True
                for d in range(4):
                    s=set()
                    aim=0
                    if cards[i][d]!="*":
                        s.add(cards[i][d])
                        aim+=1
                    if cards[j][d]!="*":
                        s.add(cards[j][d])
                        aim+=1
                    if cards[k][d]!="*":
                        s.add(cards[k][d])
                        aim+=1
                    if len(s)!=aim and len(s)!=1:
                        ok=False
                        break
                if ok:
                    return f"{i+1} {j+1} {k+1}"
    return "-1"
T=int(input())
for cas in range(1,T+1):
    print(f"Case #{cas}: {solve()}")