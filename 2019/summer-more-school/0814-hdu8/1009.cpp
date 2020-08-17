#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        int x01,x02,y01,y02,x11,x12,y11,y12;
        cin>>x01>>y01>>x02>>y02;
        //if (x01>x02) {swap(x01,x02);swap(y01,y02);}
        cin>>x11>>y11>>x12>>y12;
        //if (x11>x12) {swap(x11,x12);swap(y11,y12);}
        int ans=0;
        if (x01==x11 && x02==x12 && y01==y11 && y02==y12) ans=2;
        if (ans==0 && y11==y01 && y12==y02 && ((x11>x01 && x12<x02)||(x01>x11 && x02<x12))) ans=4;
        if (ans==0 && x11==x01 && x12==x02 && ((y11>y01 && y12<y02)||(y01>y11 && y02<y12))) ans=4;
        if (ans==0 && x01<=x11 && y01<=y11 && x12<=x02 && y12<=y02) ans=3;
        if (ans==0 && x11<=x01 && y11<=y01 && x02<=x12 && y02<=y12) ans=3;
        if (y01>=y12||x01>=x12) ans=3;
        if (y11>=y02||x11>=x02) ans=3;
        if (ans==0 && x11>x01 && x12<x02 && y12==y02) ans=5;
        if (ans==0 && x11>x01 && x12<x02 && y11==y01) ans=5;
        if (ans==0 && y11>y01 && y12<y02 && x12==x02) ans=5;
        if (ans==0 && y11>y01 && y12<y02 && x11==x01) ans=5;
        if (ans==0 && x01>x11 && x02<x12 && y02==y12) ans=5;
        if (ans==0 && x01>x11 && x02<x12 && y01==y11) ans=5;
        if (ans==0 && y01>y11 && y02<y12 && x02==x12) ans=5;
        if (ans==0 && y01>y11 && y02<y12 && x01==x11) ans=5;
        if (ans==0 && x11>x01 && x12<x02 && y12>y02 && y11<y01) ans=6;
        if (ans==0 && x01>x11 && x02<x12 && y02>y12 && y01<y11) ans=6;
        if (ans==0) ans=4;
        cout<<ans<<endl;
    }
}