#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc,char**argv)
{
	registerTestlibCmd(argc,argv);
	int T=inf.readInt(1,1000),mat=0;
	for(int j=T;j;--j)
	{
		int x=ouf.readInt(0,2),y=ans.readInt(0,2);
		if(x==y) ++mat;
	}
	if(T-mat<=10) quitf(_ok,"good job, match=%d",mat);
	else quitf(_wa,"wrong answer, match=%d",mat);
}
 
