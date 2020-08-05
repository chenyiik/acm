#include<cstdio>
#define M 2000005
char str[M];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int i,n,ans=0,spc=0;
        scanf("%d %s",&n,str+1);
        for(i=n;i>0;i--){
            if(str[i]=='2'||str[i]=='3')
                ans++;
            else if(str[i]=='0')
                    spc++;
            else{
                if(spc>0){
                    spc--;
                    ans++;
                }else{
                    spc++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}