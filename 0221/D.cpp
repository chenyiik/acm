#include<cstdio>
#include<algorithm>
#include<cstring>
#define M 1000005
using namespace std;
char str[M],ans[M];
int cnt[30];
int ak[30];
bool cmp(int a,int b){
    return cnt[a]<cnt[b];
}
int main(){
    scanf("%s",str);
    int i;
    int n=(strlen(str)+1)/2;
    int kd=0,p=0;
    for(i=0;i<2*n;i++){
        if(cnt[str[i]-'a']==0){
            kd++;
            ak[p++]=str[i]-'a';
        }
        cnt[str[i]-'a']++;
    }
    if(kd==1)puts("NO");
    else if(kd==2){
        int chr[2];
        chr[0]=ak[0];
        chr[1]=ak[1];
        if(cnt[chr[0]]>cnt[chr[1]])
            swap(chr[0],chr[1]);
        if(cnt[chr[0]]==1){
            if(n==1){
                printf("YES\n%c%c\n",chr[0]+'a',chr[1]+'a');
            }else
                puts("NO");
        }else if(cnt[chr[0]]==2){
            if(n==2){
                for(i=0;i<2*n;i++){
                    if(i==0||i==n+1)
                        ans[i]=chr[0]+'a';
                    else
                        ans[i]=chr[1]+'a';
                }
                printf("YES\n%s\n",ans);
            }else{
                puts("NO");
            }
        }else{
            ans[0]=ans[n]=chr[0]+'a';
            cnt[chr[0]]-=2;
            for(i=0;i<2*n;i++){
                if(i==0||i==n)continue;
                if(cnt[chr[0]]>0){
                    cnt[chr[0]]--;
                    ans[i]=chr[0]+'a';
                }else{
                    ans[i]=chr[1]+'a';
                }
            }
            printf("YES\n%s\n",ans);
        }
    }else{
        sort(ak,ak+p,cmp);
        int j=0;
        ans[0]=ak[j]+'a';
        cnt[ak[j]]--;
        j++;
        ans[n]=ak[j]+'a';
        cnt[ak[j]]--;
        j=0;
        for(i=0;i<2*n;i++){
            if(i==0||i==n)
                continue;
            while(cnt[ak[j]]==0)j++;
            ans[i]=ak[j]+'a';
            cnt[ak[j]]--;
        }
        printf("YES\n%s\n",ans);
    }
    return 0;
}
