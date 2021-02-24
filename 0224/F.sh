#!/bin/bash

cd $(dirname $0)/.cmake

while true; do
	./F.r > F.in
	./F.b < F.in > F.ans
	./F < F.in > F.out

	ans=$(head -n1 F.ans)
	out=$(head -n1 F.out)

	if [ "$ans" != "$out" ]; then
		echo "diff"
		break
	fi
	echo "$ans $out"
done

