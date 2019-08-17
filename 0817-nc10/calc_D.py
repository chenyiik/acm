import random
n=random.randint(1,5)
mn=random.randint(3000000,int(1e18))
print(n,mn)
for i in range(n):
    a=random.randint(1,int(1e5))
    b=random.randint(0,a)
    print(a,b)
