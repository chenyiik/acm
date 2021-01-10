#include<cstdio>
#include<algorithm>
#define M 25
#define BM 10005
using namespace std;
char str[BM][M];
int dat[BM];
int UP[BM],DOWN[BM];
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%s %d",str[i],&dat[i]);
    for(i=1;i<=n;i++)
        UP[i]=min(10000,dat[i]*100+49);
    bool flag=1;
    for(i=1;i<=n;i++){
        int tmp=10000;
        for(j=1;j<=n;j++){
            if(i==j)continue;
            tmp-=UP[j];
        }
        DOWN[i]=max(max(0,tmp),dat[i]*100-50);
        if(DOWN[i]>UP[i]){
            flag=0;
            break;
        }
    }
    if(flag){
        for(i=1;i<=n;i++){
            int tmp=10000;
            for(j=1;j<=n;j++){
                if(i==j)continue;
                tmp-=DOWN[j];
            }
            UP[i]=min(tmp,UP[i]);
            if(DOWN[i]>UP[i]){
                flag=0;
                break;
            }
        }
    }
    if(!flag)puts("IMPOSSIBLE");
    else for(i=1;i<=n;i++)
        printf("%s %.2f %.2f\n",str[i],DOWN[i]/100.0,UP[i]/100.0);
    return 0;
}
