n=input()
a=input().strip().split()
for i in range(len(a)):
    if a[i]=="mumble":
        a[i]=-1
    else:
        a[i]=int(a[i])
for i in range(len(a)):
    if a[i]!=-1 and a[i]!=(i+1):
        print("something is fishy")
        exit(0)
print("makes sense")
