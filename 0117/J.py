def s(c):
    if c=='a':
        return 'a'
    k=s(chr(ord(c)-1))
    return k+c+k
n=int(input())
print(s('z')[n-1])
