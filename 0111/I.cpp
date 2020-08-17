#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin>>n)
    {
        double sum=0;
        while (n--)
        {
            string s;
            cin>>s;
            int v=s[s.size()-1]-'0';
            if (v<=4) sum-=0.001*v;
            else sum+=(10-v)*0.001;
        }
        printf("%.3f\n",sum);
    }
}