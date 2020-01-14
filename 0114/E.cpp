#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&x);
        if (x<6)
        {
            puts("-1");
            continue;
        }
        if (x<28)
        {
            puts("6");
            continue;
        }
        if (x<496)
        {
            puts("28");
            continue;
        }
        if (x<8128)
        {
            puts("496");
            continue;
        }
        puts("8128");
    }
}