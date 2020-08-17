t=input()
q=int(input())
for x in range(q):
    s=input()
    if (len(s)<len(t)):
        if (s in t):
            print("my child!")
        else:
            print("oh, child!")
    elif (len(s)>len(t)):
        if (t in s):
            print("my teacher!")
        else:
            print("senior!")
    else:
        if (s==t):
            print("jntm!")
        else:
            print("friend!")