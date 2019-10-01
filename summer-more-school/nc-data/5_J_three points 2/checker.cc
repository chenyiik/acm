#include "testlib.h"

using namespace std;
#define SZ(X) ((int)(X).size())
typedef long long LL;
const int MIN_N = 3;
const int MAX_N = 200 * 1000;
const int MIN_Q = 1;
const int MAX_Q = 200 * 1000;
int n,_a,_b,_c;
// 0-based
#define MAX_LV 18
vector<int> e[MAX_N];
int jump[MAX_LV+1][MAX_N],lv[MAX_N];
void __init(int x,int lt){
    jump[0][x]=lt;
    for(int i=0; i < SZ(e[x]); i++){
        int y=e[x][i];
        if(y!=lt){
            lv[y]=lv[x]+1;
            __init(y,x);
        }
    }
}
int adv(int x,int v){
    for(int i=0;(1<<i)<=v;i++){
        if((v>>i)&1)x=jump[i][x];
    }
    return x;
}
int lca(int x,int y){
    if(lv[x]>lv[y])x=adv(x,lv[x]-lv[y]);
    else y=adv(y,lv[y]-lv[x]);
    if(x==y)return x;
    for(int i=MAX_LV;i>=0;i--)
        if(jump[i][x]!=jump[i][y]){x=jump[i][x];y=jump[i][y];}
    return jump[0][x];
}
int dis(int x,int y){
    int z=lca(x,y);
    return lv[x]+lv[y]-lv[z]*2;
}
void build(int root,int N){
    __init(root,root);
    for(int i=1;i<=MAX_LV;i++){
        for(int x = 0;x < N; x++) {
            jump[i][x] = jump[i-1][jump[i-1][x]];
        }
    }
}
int read_output(InStream& ufo,TResult _res, int cs){
    int x=ufo.readInt(-1,n-1);
    if(x==-1) return -1;
    int y=ufo.readInt(0,n-1);
    int z=ufo.readInt(0,n-1);
    if(dis(x,y) != _a) quitf(_res,"the distance between X and Y is wrong on %d query", cs);
    if(dis(x,z) != _b) quitf(_res,"the distance between X and Z is wrong on %d query", cs);
    if(dis(y,z) != _c) quitf(_res,"the distance between Y and Z is wrong on %d query", cs);
    return 1;
}
int main(int argc, char * argv[])
{
    setName("checker of baidu-astar2019-digits-sum");
    registerTestlibCmd(argc, argv);
    n = inf.readInt();
    for(int i=1;i<n;i++){
        int x,y;
        x=inf.readInt();
        y=inf.readInt();
        e[x].push_back(y);
        e[y].push_back(x);
    }
    build(0,n);
    int Q = inf.readInt();
    for(int cs = 1; cs <= Q; cs++) {
        _a=inf.readInt();
        _b=inf.readInt();
        _c=inf.readInt();
        int ans_res = read_output(ans, _fail, cs);
        int ouf_res = read_output(ouf, _wa, cs);
        if(ans_res != ouf_res) {
            if(ans_res == 1)quitf(_wa,"author found solution but user didn't on test %d", cs);
            else quitf(_fail, "user found solution but author didn't on test %d", cs);
        }
    }
    if (!ouf.seekEof()) {
        quitf(_wa, "Participant output contains extra tokens");
    }
    quitf(_ok, "complete %d queries", Q);
}

