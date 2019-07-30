while True:
	try:
		str=input().split()
		x=eval(str[0])
		a=eval(str[1])
		y=eval(str[2])
		b=eval(str[3])
		num=x*b-a*y
		if num<0:
			print("<")
		elif num==0:
			print("=")
		else:
			print(">")
	except EOFError:
		break
