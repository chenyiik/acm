count = 0
for i in range(1,43) :
	num = 2 ** i
	max_num = 10 ** (10 ** 5)

	count = count // num * num
#if count == 0:
	count += num
	print("%3d " % i)
	while count < max_num :
		d = count
		while d > 0 and (d % 10 == 1 or d % 10 == 2) :
			d //= 10
		if d == 0:
			print("%20d" % count)
			break
		count += num
