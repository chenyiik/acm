#include<bits/stdc++.h>
using namespace std;
int cnt(int n,int x)
{
    if(x>9||x<0||n<0) return 0;
    int i=1;
    int high=n;
    int cnt=0;
    while(high!=0)
    {
        high=n/pow(10,i);
        int temp=n/pow(10,i-1);
        int cur=temp%10;
        int low=n-temp*pow(10,i-1);
        if(cur<x) cnt+=high*pow(10,i-1);
        else if(cur>x) cnt+=(high+1)*pow(10,i-1);
        else
        {
            cnt+=high*pow(10,i-1);
            cnt+=(low+1);
        }
        i++;
    }
    return cnt;
}
int main()
{
    cout<<cnt(199990,1)<<endl;
}