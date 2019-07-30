#include<iostream>
using namespace std;
int main()
{
	for (int i=1;i<=100;i++)
	{
		int lv=0;
		for (int k=0;k<=i-1;k++) lv|=(1<<k);
		//cout<<lv<<endl;
		lv<<=(i-1);
		int sum=0;
		for (int j=1;j<lv;j++)
		{
			if (lv%j==0) sum+=j;
		}
		cout<<lv<<endl;
		//system("pause");
		if (sum==lv) cout<<lv<<endl;
	}
	return 0;
}
