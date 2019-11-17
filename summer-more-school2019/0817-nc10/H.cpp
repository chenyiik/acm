#include<bits/stdc++.h>
using namespace std;
int connected[7][7];
void read(int &x)
{
    char ch;x=0;
    while (ch=getchar(),!isdigit(ch));
    do {x=x*10+ch-'0';ch=getchar();}while (isdigit(ch));
}
int main()
{
    int T;
    read(T);
    while (T--)
    {
        memset(connected,0,sizeof(connected));
        int a,b;
        for (int i=1;i<=5;i++)
        {
            read(a),read(b);
            connected[a][++connected[a][0]]=b;
            connected[b][++connected[b][0]]=a;
        }
        int d[5];memset(d,0,sizeof(d));
        for (int i=1;i<=6;i++) d[connected[i][0]]++;
        if (d[4]==1) {puts("2,2-dimethylbutane");continue;}
        if (d[3]==0) {puts("n-hexane");continue;}
        if (d[3]==2) {puts("2,3-dimethylbutane");continue;}
        for (int i=1;i<=6;i++)
        if (connected[i][0]==3)
        {
            int ck=0;
            for (int j=1;j<=connected[i][0];j++) if (connected[connected[i][j]][0]==1) ++ck;
            if (ck==2) {puts("2-methylpentane");break;}
            else {puts("3-methylpentane");break;}
        }
    }
}