#include<cstdio>
#include<cstring>
char A[3][40];
int main(){
    scanf("%s%s%s",A[0],A[1],A[2]);
    int cnt=3;
    for(int i=0;i<3;i++){
        if(strcmp(A[i],"bubble")==0||strcmp(A[i],"tapioka")==0)
            cnt--;
        else
            printf("%s%c",A[i]," \n"[i==2]);
    }
    if(cnt==0){
        puts("nothing");
    }
    return 0;
}
