#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cmath>
#define LL long long
using namespace std;
void Rd(LL &res){
    res=0;
    char c;
    while(c=getchar(),!isdigit(c));
    do{
        res=(res*10)+(c^48);
    }while(c=getchar(),isdigit(c));
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL n;
        Rd(n);
        if(n==1||n==24)
            puts("Fake news!");
        else
            puts("Nobody knows it better than me!");
    }
    return 0;
}