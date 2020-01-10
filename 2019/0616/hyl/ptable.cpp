#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
long long power(long long a,long long b)
{
    long long ans=1;
    while (b--) ans*=a;
    return ans;
}
int main()
{
    for (long long i=1;i<=10;i++) {
        for (long long j = 1; j <= 10; j++) cout << gcd(power(5, i) + power(7, i), power(5, j) + power(7, j)) << "\t";
        cout << endl;
    }
    return 0;
}