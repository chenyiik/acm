#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

typedef long long LL;

const LL mod = LL(1e9) + 7;
long long mi[1000050<<1],c[1000050];
unordered_map<LL, LL> M;
LL quick(LL x,LL a);
void init();
LL f(LL n) { return c[n]; }

struct P 
{
	stack<LL> S;
	void push(LL x);
};


int main()
{
	init();
	int n; scanf("%d", &n);
	P S;
	while (n--)
	{
		LL x = 0; scanf("%lld", &x);
		S.push(x);
	}
	S.push(-0x80000000LL);
	LL ans = 1;
	for (auto i : M)
	{
		LL s = f(i.first);
		LL t = quick(s, i.second);
		ans = (ans * t) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}

LL quick(LL x,LL a){
    LL res=1;
    while(a>0){
        if(a&1)res=1LL*res*x%mod;
        x=1LL*x*x%mod;
        a>>=1;
    }
    return res;
}

LL inv(LL x){
    return quick(x,mod-2);
}

void init()
{
    mi[0]=1;
    for (long long i=1;i<=2*(1000005);i++) mi[i]=i*mi[i-1]%(long long)(1e9+7);
    for (long long i=1;i<=1000005;i++) c[i]=mi[2*i]*inv(mi[i])%mod*inv(mi[i])%mod*inv(i+1)%mod;
}

void map_insert(LL k)
{
	auto it = M.find(k);
	if (it == M.end())
		M[k] = 1;
	else
		it->second++;
}

void P::push(const LL x)
{
	LL now = x, tot = 0;
	while (!S.empty() && x < S.top())
	{
		if (S.top() == now)
			tot++;
		else
		{
			if (tot >= 2)
				map_insert(tot);
			now = S.top(), tot = 1;
		}
		S.pop();
	}
	if (tot >= 2)
		map_insert(tot);
	S.push(x);
}
