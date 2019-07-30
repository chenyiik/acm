T=input("")
for cas in range(0,T):
	e=input("")
	print(type(e))
	n=e
	cnt=0
	while(e>0):
		if(e%2==1):
			cnt+=1
		e//=2
	print(n-cnt)

