#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL ans[10][400] = {
	{0LL}, 
	{0LL, 1LL, 199981LL, 199982LL, 199983LL, 199984LL, 199985LL, 199986LL, 199987LL, 199988LL, 199989LL, 199990LL, 200000LL, 200001LL, 1599981LL, 1599982LL, 1599983LL, 1599984LL, 1599985LL, 1599986LL, 1599987LL, 1599988LL, 1599989LL, 1599990LL, 2600000LL, 2600001LL, 13199998LL, 35000000LL, 35000001LL, 35199981LL, 35199982LL, 35199983LL, 35199984LL, 35199985LL, 35199986LL, 35199987LL, 35199988LL, 35199989LL, 35199990LL, 35200000LL, 35200001LL, 117463825LL, 500000000LL, 500000001LL, 500199981LL, 500199982LL, 500199983LL, 500199984LL, 500199985LL, 500199986LL, 500199987LL, 500199988LL, 500199989LL, 500199990LL, 500200000LL, 500200001LL, 501599981LL, 501599982LL, 501599983LL, 501599984LL, 501599985LL, 501599986LL, 501599987LL, 501599988LL, 501599989LL, 501599990LL, 502600000LL, 502600001LL, 513199998LL, 535000000LL, 535000001LL, 535199981LL, 535199982LL, 535199983LL, 535199984LL, 535199985LL, 535199986LL, 535199987LL, 535199988LL, 535199989LL, 535199990LL, 535200000LL, 535200001LL, 1111111110LL}, 
	{0LL, 28263827LL, 35000000LL, 242463827LL, 500000000LL, 528263827LL, 535000000LL, 10000000000LL, 10028263827LL, 10035000000LL, 10242463827LL, 10500000000LL, 10528263827LL, 10535000000LL}, 
	{0LL, 371599983LL, 371599984LL, 371599985LL, 371599986LL, 371599987LL, 371599988LL, 371599989LL, 371599990LL, 371599991LL, 371599992LL, 500000000LL, 10000000000LL, 10371599983LL, 10371599984LL, 10371599985LL, 10371599986LL, 10371599987LL, 10371599988LL, 10371599989LL, 10371599990LL, 10371599991LL, 10371599992LL, 10500000000LL, 20000000000LL, 20371599983LL, 20371599984LL, 20371599985LL, 20371599986LL, 20371599987LL, 20371599988LL, 20371599989LL, 20371599990LL, 20371599991LL, 20371599992LL, 20500000000LL},
	{0LL, 499999984LL, 499999985LL, 499999986LL, 499999987LL, 499999988LL, 499999989LL, 499999990LL, 499999991LL, 499999992LL, 499999993LL, 500000000LL, 10000000000LL, 10499999984LL, 10499999985LL, 10499999986LL, 10499999987LL, 10499999988LL, 10499999989LL, 10499999990LL, 10499999991LL, 10499999992LL, 10499999993LL, 10500000000LL, 20000000000LL, 20499999984LL, 20499999985LL, 20499999986LL, 20499999987LL, 20499999988LL, 20499999989LL, 20499999990LL, 20499999991LL, 20499999992LL, 20499999993LL, 20500000000LL, 30000000000LL, 30499999984LL, 30499999985LL, 30499999986LL, 30499999987LL, 30499999988LL, 30499999989LL, 30499999990LL, 30499999991LL, 30499999992LL, 30499999993LL, 30500000000LL},
	{0LL, 10000000000LL, 20000000000LL, 30000000000LL, 40000000000LL},
	{0LL, 9500000000LL, 9628399986LL, 9628399987LL, 9628399988LL, 9628399989LL, 9628399990LL, 9628399991LL, 9628399992LL, 9628399993LL, 9628399994LL, 9628399995LL, 10000000000LL, 19500000000LL, 19628399986LL, 19628399987LL, 19628399988LL, 19628399989LL, 19628399990LL, 19628399991LL, 19628399992LL, 19628399993LL, 19628399994LL, 19628399995LL, 20000000000LL, 29500000000LL, 29628399986LL, 29628399987LL, 29628399988LL, 29628399989LL, 29628399990LL, 29628399991LL, 29628399992LL, 29628399993LL, 29628399994LL, 29628399995LL, 30000000000LL, 39500000000LL, 39628399986LL, 39628399987LL, 39628399988LL, 39628399989LL, 39628399990LL, 39628399991LL, 39628399992LL, 39628399993LL, 39628399994LL, 39628399995LL, 40000000000LL, 49500000000LL, 49628399986LL, 49628399987LL, 49628399988LL, 49628399989LL, 49628399990LL, 49628399991LL, 49628399992LL, 49628399993LL, 49628399994LL, 49628399995LL, 50000000000LL, 59500000000LL, 59628399986LL, 59628399987LL, 59628399988LL, 59628399989LL, 59628399990LL, 59628399991LL, 59628399992LL, 59628399993LL, 59628399994LL, 59628399995LL},
	{0LL, 9465000000LL, 9471736170LL, 9500000000LL, 9757536170LL, 9965000000LL, 9971736170LL, 10000000000LL, 19465000000LL, 19471736170LL, 19500000000LL, 19757536170LL, 19965000000LL, 19971736170LL, 20000000000LL, 29465000000LL, 29471736170LL, 29500000000LL, 29757536170LL, 29965000000LL, 29971736170LL, 30000000000LL, 39465000000LL, 39471736170LL, 39500000000LL, 39757536170LL, 39965000000LL, 39971736170LL, 40000000000LL, 49465000000LL, 49471736170LL, 49500000000LL, 49757536170LL, 49965000000LL, 49971736170LL, 50000000000LL, 59465000000LL, 59471736170LL, 59500000000LL, 59757536170LL, 59965000000LL, 59971736170LL, 60000000000LL, 69465000000LL, 69471736170LL, 69500000000LL, 69757536170LL, 69965000000LL, 69971736170LL},
	{0LL, 9465000000LL, 9486799989LL, 9486799990LL, 9486799991LL, 9486799992LL, 9486799993LL, 9486799994LL, 9486799995LL, 9486799996LL, 9486799997LL, 9497400000LL, 9498399989LL, 9498399990LL, 9498399991LL, 9498399992LL, 9498399993LL, 9498399994LL, 9498399995LL, 9498399996LL, 9498399997LL, 9500000000LL, 9882536171LL, 9965000000LL, 9986799989LL, 9986799990LL, 9986799991LL, 9986799992LL, 9986799993LL, 9986799994LL, 9986799995LL, 9986799996LL, 9986799997LL, 9997400000LL, 9998399989LL, 9998399990LL, 9998399991LL, 9998399992LL, 9998399993LL, 9998399994LL, 9998399995LL, 9998399996LL, 9998399997LL, 
		10000000000LL, 19465000000LL, 19486799989LL, 19486799990LL, 19486799991LL, 19486799992LL, 19486799993LL, 19486799994LL, 19486799995LL, 19486799996LL, 19486799997LL, 19497400000LL, 19498399989LL, 19498399990LL, 19498399991LL, 19498399992LL, 19498399993LL, 19498399994LL, 19498399995LL, 19498399996LL, 19498399997LL, 19500000000LL, 19882536171LL, 19965000000LL, 19986799989LL, 19986799990LL, 19986799991LL, 19986799992LL, 19986799993LL, 19986799994LL, 19986799995LL, 19986799996LL, 19986799997LL, 19997400000LL, 19998399989LL, 19998399990LL, 19998399991LL, 19998399992LL, 19998399993LL, 19998399994LL, 19998399995LL, 19998399996LL, 19998399997LL, 
		20000000000LL, 29465000000LL, 29486799989LL, 29486799990LL, 29486799991LL, 29486799992LL, 29486799993LL, 29486799994LL, 29486799995LL, 29486799996LL, 29486799997LL, 29497400000LL, 29498399989LL, 29498399990LL, 29498399991LL, 29498399992LL, 29498399993LL, 29498399994LL, 29498399995LL, 29498399996LL, 29498399997LL, 29500000000LL, 29882536171LL, 29965000000LL, 29986799989LL, 29986799990LL, 29986799991LL, 29986799992LL, 29986799993LL, 29986799994LL, 29986799995LL, 29986799996LL, 29986799997LL, 29997400000LL, 29998399989LL, 29998399990LL, 29998399991LL, 29998399992LL, 29998399993LL, 29998399994LL, 29998399995LL, 29998399996LL, 29998399997LL, 
		30000000000LL, 39465000000LL, 39486799989LL, 39486799990LL, 39486799991LL, 39486799992LL, 39486799993LL, 39486799994LL, 39486799995LL, 39486799996LL, 39486799997LL, 39497400000LL, 39498399989LL, 39498399990LL, 39498399991LL, 39498399992LL, 39498399993LL, 39498399994LL, 39498399995LL, 39498399996LL, 39498399997LL, 39500000000LL, 39882536171LL, 39965000000LL, 39986799989LL, 39986799990LL, 39986799991LL, 39986799992LL, 39986799993LL, 39986799994LL, 39986799995LL, 39986799996LL, 39986799997LL, 39997400000LL, 39998399989LL, 39998399990LL, 39998399991LL, 39998399992LL, 39998399993LL, 39998399994LL, 39998399995LL, 39998399996LL, 39998399997LL, 
		40000000000LL, 49465000000LL, 49486799989LL, 49486799990LL, 49486799991LL, 49486799992LL, 49486799993LL, 49486799994LL, 49486799995LL, 49486799996LL, 49486799997LL, 49497400000LL, 49498399989LL, 49498399990LL, 49498399991LL, 49498399992LL, 49498399993LL, 49498399994LL, 49498399995LL, 49498399996LL, 49498399997LL, 49500000000LL, 49882536171LL, 49965000000LL, 49986799989LL, 49986799990LL, 49986799991LL, 49986799992LL, 49986799993LL, 49986799994LL, 49986799995LL, 49986799996LL, 49986799997LL, 49997400000LL, 49998399989LL, 49998399990LL, 49998399991LL, 49998399992LL, 49998399993LL, 49998399994LL, 49998399995LL, 49998399996LL, 49998399997LL, 
		50000000000LL, 59465000000LL, 59486799989LL, 59486799990LL, 59486799991LL, 59486799992LL, 59486799993LL, 59486799994LL, 59486799995LL, 59486799996LL, 59486799997LL, 59497400000LL, 59498399989LL, 59498399990LL, 59498399991LL, 59498399992LL, 59498399993LL, 59498399994LL, 59498399995LL, 59498399996LL, 59498399997LL, 59500000000LL, 59882536171LL, 59965000000LL, 59986799989LL, 59986799990LL, 59986799991LL, 59986799992LL, 59986799993LL, 59986799994LL, 59986799995LL, 59986799996LL, 59986799997LL, 59997400000LL, 59998399989LL, 59998399990LL, 59998399991LL, 59998399992LL, 59998399993LL, 59998399994LL, 59998399995LL, 59998399996LL, 59998399997LL, 
		60000000000LL, 69465000000LL, 69486799989LL, 69486799990LL, 69486799991LL, 69486799992LL, 69486799993LL, 69486799994LL, 69486799995LL, 69486799996LL, 69486799997LL, 69497400000LL, 69498399989LL, 69498399990LL, 69498399991LL, 69498399992LL, 69498399993LL, 69498399994LL, 69498399995LL, 69498399996LL, 69498399997LL, 69500000000LL, 69882536171LL, 69965000000LL, 69986799989LL, 69986799990LL, 69986799991LL, 69986799992LL, 69986799993LL, 69986799994LL, 69986799995LL, 69986799996LL, 69986799997LL, 69997400000LL, 69998399989LL, 69998399990LL, 69998399991LL, 69998399992LL, 69998399993LL, 69998399994LL, 69998399995LL, 69998399996LL, 69998399997LL, 
		70000000000LL, 79465000000LL, 79486799989LL, 79486799990LL, 79486799991LL, 79486799992LL, 79486799993LL, 79486799994LL, 79486799995LL, 79486799996LL, 79486799997LL, 79497400000LL, 79498399989LL, 79498399990LL, 79498399991LL, 79498399992LL, 79498399993LL, 79498399994LL, 79498399995LL, 79498399996LL, 79498399997LL, 79500000000LL, 79882536171LL, 79965000000LL, 79986799989LL, 79986799990LL, 79986799991LL, 79986799992LL, 79986799993LL, 79986799994LL, 79986799995LL, 79986799996LL, 79986799997LL, 79997400000LL, 79998399989LL, 79998399990LL, 79998399991LL, 79998399992LL, 79998399993LL, 79998399994LL, 79998399995LL, 79998399996LL, 79998399997LL},
	{0LL, 10000000000LL, 20000000000LL, 30000000000LL, 40000000000LL, 50000000000LL, 60000000000LL, 70000000000LL, 80000000000LL}
};


int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int d; long long n; scanf("%d%lld", &d, &n);
		int pos = 399;
		while (ans[d][pos] == 0)
			pos--;
		while (ans[d][pos] > n)
			pos--;
		cout << ans[d][pos] << endl;
	}
}

/*
int main()
{
	long long sum = 0LL, d = 5;
	for (long long i = 1; i <= LL(2.222222222e10); i++)
	{
		long long s = i;
		while (s)
			sum += (s % 10 == d)LL, s /= 10;
		if (sum == i)
			cout << i << endl;
	}
	return 0;
}
*/