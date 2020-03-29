#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
int where(char ch,double d,double l)
{
    double angle=d*pi/180;
    if (ch=='D') angle=2*pi-angle;
    if (ch=='C') angle=4.0/3.0*pi-angle;
    if (ch=='B') angle=5.0/3.0*pi-angle;
    double x=l*cos(angle),y=l*sin(angle);
    while (y<-sqrt(3.0))
    {
        y+=sqrt(3.0);x+=1;
    }
    y+=sqrt(3.0);x+=1;
    y=y*2/sqrt(3);
    x=x-0.5*y;
    while (x<0) x+=2;
    while (x>2) x-=2;
    if (x<1 && y<1) return ((x+y)<1)?2:1;
    if (x>1 && y<1) return ((x+y)<2)?3:4;
    if (x<1 && y>1) return ((x+y)<2)?4:3;
    if (x>1 && y>1) return ((x+y)<3)?1:2;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string s1,s2;
    int d1,d2,l1,l2;
    cin>>s1>>d1>>l1>>s2>>d2>>l2;
    int spe1=where(s1.front(),d1,l1),spe2=where(s2.front(),d2,l2);
    cout<<vector<string>({"NO","YES"})[spe1==spe2]<<endl;
}