#include<cstdio>
#define M 1005
char str[M][M];
int down[M][M];
int right[M][M];
int sum[M][M];
int calc(int x,int y,int n,int m){
    return sum[x+n-1][y+m-1]-sum[x-1][y+m-1]-sum[x+n-1][y-1]+sum[x-1][y-1];
}
int color(int x,int y,int n,int m){
    int cnt=calc(x,y,n,m);
    if(cnt==n*m)return 1;
    if(cnt==0)return 0;
    return -1;
}
bool surround(int x,int y,int a,int b){
    return calc(x-1,y-1,1,a+2)+calc(x-1,y-1,b+2,1)+calc(x-1,y+a,b+2,1)+calc(x+b,y-1,1,a+2)==0;
}
bool verifyA(int i,int j,int x,int y){
    bool flag=1;
    if(color(i,j,x,2*x+y)!=1)flag=0;
    if(color(i,j,3*x+2*y,x)!=1)flag=0;
    if(color(i,j+x+y,3*x+2*y,x)!=1)flag=0;
    if(color(i+x+y,j,x,2*x+y)!=1)flag=0;
    if(color(i+x,j+x,y,y)!=0)flag=0;
    if(color(i+2*x+y,j+x,x+y,y)!=0)flag=0;
    return flag;
}
bool verifyB(int i,int j,int x,int y){
    bool flag=1;
    if(color(i,j,x,2*x+y)!=1)flag=0;
    if(color(i,j,3*x+2*y,x)!=1)flag=0;
    if(color(i,j+x+y,3*x+2*y,x)!=1)flag=0;
    if(color(i+x+y,j,x,2*x+y)!=1)flag=0;
    if(color(i+2*x+2*y,j,x,2*x+y)!=1)flag=0;
    if(color(i+x,j+x,y,y)!=0)flag=0;
    if(color(i+2*x+y,j+x,y,y)!=0)flag=0;
    return flag;
}
bool verifyC(int i,int j,int x,int y){
    bool flag=1;
    if(color(i,j,x,2*x+y)!=1)flag=0;
    if(color(i,j,3*x+2*y,x)!=1)flag=0;
    if(color(i+2*x+2*y,j,x,2*x+y)!=1)flag=0;
    if(color(i+x,j+x,x+2*y,x+y)!=0)flag=0;
    return flag;
}
int main(){
    int i,j,n,m;
    int ansa=0,ansb=0,ansc=0;
    scanf("%d %d",&m,&n);
    for(i=1;i<=n;i++)
        scanf("%s",str[i]+1);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(str[i][j]=='#'){
                bool flag=1;
                for(int tx=-1;tx<=1;tx++)
                    for(int ty=-1;ty<=1;ty++){
                        if(tx==0&&ty==0)continue;
                        if(str[i+tx][j+ty]!='.'){
                            flag=0;
                            break;
                        }
                    }
                if(flag)
                    str[i][j]='.';
            }
        }
    }
    for(j=1;j<=m;j++){
        int tmp=n+1;
        for(i=n;i>0;i--){
            if(str[i][j]=='.')
                tmp=i;
            down[i][j]=tmp;
        }
    }
    for(i=1;i<=n;i++){
        int tmp=m+1;
        for(j=m;j>0;j--){
            if(str[i][j]=='.')
                tmp=j;
            right[i][j]=tmp;
        }
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(str[i][j]=='#');
    for(i=2;i<n;i++){
        for(j=2;j<m;j++){
            if(str[i][j]=='.')
                continue;
            int a=right[i][j]-j;
            int b=down[i][j]-i;
            int x=2*a-b;
            int y=-3*a+2*b;
            if(x<=0)continue;
            if(y<=0)continue;
            if(!surround(i,j,a,b))continue;
            if(verifyA(i,j,x,y)){
                ansa++;
            }else if(verifyB(i,j,x,y)){
                ansb++;
            }else if(verifyC(i,j,x,y)){
                ansc++;
            }
        }
    }
    printf("%d %d %d\n",ansa,ansb,ansc);
    return 0;
}
