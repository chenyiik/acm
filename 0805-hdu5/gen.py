print(10)
for x in range(2):
    print(100000)
    for i in range(99999):
        print(2**30-1,end=' ')
    print('1')
    for i in range(100000):
        print(2**30-1,end=' ')
    print('')

for x in range(8):
    print(100)
    for i in range(99):
        print(2**30-1,end=' ')
    print('1')
    for i in range(100):
        print(2**30-1,end=' ')
    print('')
