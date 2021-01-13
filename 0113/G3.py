n = ''
for i in range(42):
	if eval('1' + n) % (2**(i+1)) == 0:
		n = '1' + n
	else:
	 	n = '2' + n
print(n)
