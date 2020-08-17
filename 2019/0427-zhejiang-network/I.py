T=input("")
for i in range(0,T):
	str=raw_input()
	k=str.split()
	a=int(k[0])
	b=int(k[1])
	if (a-1)%3==0 or (a-1)%3==2:
		a=0
	else:
	 	a=1
	if b%3==0 or b%3==2:
		b=0
	else:
	 	b=1
	c=(a-b+2)%2
	print(c)
