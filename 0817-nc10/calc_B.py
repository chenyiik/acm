s=['COFFEE','CHICKEN']
for i in range(2,10):
	s.append(s[i-2]+s[i-1])
for i in range(10):
	print(s[i])
