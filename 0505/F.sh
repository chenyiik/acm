#!/bin/bash

set +x

g++ F.cc -O2 --std=c++11 -Wall -o F

while :; do 
	echo "run r.py"
	python3 R.py > F.in
	echo "run f.py"
	python3 F.py < F.in > F.ans
	echo "run f.cc"
	./F < F.in > F.out
	echo "check"
	diff F.ans F.out
	if [ $? -eq 0 ]; then
		echo "succ"
	else
		echo "fail"
		break
	fi
done
