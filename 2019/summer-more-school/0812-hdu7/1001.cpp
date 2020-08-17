#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 105005
using namespace std;
char A[M],B[M],C[M];
int tot;
int mark[M];
int x,y,z;
bool solve(int pa,int pb,int pc,int cnt){
    int a,b,c,tmp=0;
    if(pa==0&&pb!=0&&pc!=0){
        int tmpy=0,tmpz=0;
        do{
            pb--;
            pc--;
            if(pb<0)b=mark[cnt]==tot;
            else b=(B[pb]^48)+(mark[cnt]==tot);
            if(b>=10){
                b-=10;
                mark[cnt+1]=tot;
            }
            c=(C[pc]^48);
            if(C[pc+1]=='\0'&&c!=0&&b==0){
                tmpz++;
                pc++;
                c=0;
            }
            if(B[pb+1]=='\0'&&c==0&&b!=0){
                tmpy++;
                pb++;
                b=0;
            }
            cnt++;
        }while(b==c&&pb>=0&&pc>0);
        tot++;
        if(b==c){
            z+=tmpz;
            y+=tmpy;
            return 1;
        }
        return 0;
    }
    if(pb==0&&pa!=0&&pc!=0){
        int tmpx=0,tmpz=0;
        do{
            pa--;
            pc--;
            if(pa<0)a=mark[cnt]==tot;
                a=(A[pa]^48)+(mark[cnt]==tot);
            if(a>=10){
                a-=10;
                mark[cnt+1]=tot;
            }
            c=(C[pc]^48);
            if(C[pc+1]=='\0'&&c!=0&&a==0){
                tmpz++;
                pc++;
                c=0;
            }
            if(A[pa+1]=='\0'&&c==0&&a!=0){
                tmpx++;
                pa++;
                a=0;
            }
            cnt++;
        }while(a==c&&pa>=0&&pc>0);
        tot++;
        if(a==c){
            z+=tmpz;
            x+=tmpx;
            return 1;
        }
        return 0;
    }
    if(pa<=0&&pb<=0&&pc<=1)
        return 1;
    if(pc==0&&(pa!=0||pb!=0))
        return 0;
    a=A[pa-1]^48;
    b=B[pb-1]^48;
    c=C[pc-1]^48;
    if(mark[cnt]==tot)tmp++;
    if(a+b+tmp==10&&C[pc]=='\0'){
        //printf("a+b+tmp==10: %d:  (%d,%d) (%d,%d) (%d,%d) %d\n",cnt,pa,a,pb,b,pc,c,tmp);
        mark[cnt+1]=tot;
        z++;
        bool flag=solve(pa-1,pb-1,pc,cnt+1);
        if(flag)return 1;
        z--;
        tot++;
    }
    if(a==c&&B[pb]=='\0'){
        //printf("a==c: %d:  (%d,%d) (%d,%d) (%d,%d) %d\n",cnt,pa,a,pb,b,pc,c,tmp);
        y++;
        bool flag=solve(pa-1,pb,pc-1,cnt+1);
        if(flag)return 1;
        tot++;
        y--;
    }
    if(b==c&&A[pa]=='\0'){
        //printf("b==c: %d:  (%d,%d) (%d,%d) (%d,%d) %d\n",cnt,pa,a,pb,b,pc,c,tmp);
        x++;
        bool flag=solve(pa,pb-1,pc-1,cnt+1);
        if(flag)return 1;
        tot++;
        x--;
    }
    if(a+b+tmp==c){
        //printf("a+b+tmp==c: %d:  (%d,%d) (%d,%d) (%d,%d) %d\n",cnt,pa,a,pb,b,pc,c,tmp);
        return solve(pa-1,pb-1,pc-1,cnt+1);
    }
    if(a+b+tmp==c+10){
        //printf("a+b+tmp==c+10: %d:  (%d,%d) (%d,%d) (%d,%d) %d\n",cnt,pa,a,pb,b,pc,c,tmp);
        mark[cnt+1]=tot;
        return solve(pa-1,pb-1,pc-1,cnt+1);
    }
    return 0;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ++tot;
        x=y=z=0;
        scanf("%s %s %s",A+1,B+1,C+1);
        int la=strlen(A+1)+1;
        int lb=strlen(B+1)+1;
        int lc=strlen(C+1)+1;
        A[0]=B[0]=C[0]='0';
        while(la>1&&A[la-1]=='0'){
            x--;
            la--;
        }
        while(lb>1&&B[lb-1]=='0'){
            y--;
            lb--;
        }
        while(lc>1&&C[lc-1]=='0'){
            z--;
            lc--;
        }
        A[la]=B[lb]=C[lc]='\0';
        if(!solve(la,lb,lc,0))
            puts("-1");
        else{
            //printf("%d %d %d\n",x,y,z);
            int d=min(min(x,y),z);
            printf("%d %d %d\n",x-d,y-d,z-d);
        }
        //puts(A);
        //puts(B);
        //puts(C);
    }
    return 0;
}
