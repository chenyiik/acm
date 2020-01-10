#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,y;
    while (cin>>n>>y)
    {
        int mxx=-1,mx2=-1;
        for (int i=1;i<=n;i++)
        {
            int tmp;
            cin>>tmp;
            if (tmp>mxx) {mx2=mxx;mxx=tmp;continue;}
            if (tmp>mx2) {mx2=tmp;continue;}
        }
        //cout<<mxx<<" "<<mx2<<endl;
        for (int i=1;i<=y;i++)
        {
            int t1=mxx+i;
            int diff=y;
            if (mxx-mx2>=i) diff=i;
            cout<<max(t1,mx2+diff)<<" \n"[i==y];
        }
    }
    return 0;
}