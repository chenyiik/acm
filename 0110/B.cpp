#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    bool fst=true;
    while(~scanf("%d",&n) && n)
    {
        if (!fst) puts("");else fst=false;
        int num1=0,num2=0;
        while (n--)
        {
            char s[105];
            int num;
            scanf("%s %d",s,&num);
            if (s[0]=='D') {num2+=num;printf("DROP 2 %d\n",num);}
            if (s[0]=='T')
            {
                int diff=min(num,num1);
                if (diff>0)
                {
                    printf("TAKE 1 %d\n",diff);
                    num-=diff,num1-=diff;
                }
                if (num>0)
                {
                    printf("MOVE 2->1 %d\n",num2);
                    num1+=num2;num2=0;
                    printf("TAKE 1 %d\n",num);
                    num1-=num;
                }
            }
        }
    }
}