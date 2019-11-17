#include "testlib.h"
using namespace std;

const int MAXN = 100010;
const int INF = 1e9;
int tcase,n;
int a[MAXN],as[MAXN],std_ans[MAXN];

int median(int x,int y,int z) {
    int mx = max(max(x,y),z);
    int mi = min(min(x,y),z);
    return x - mx - mi + y + z;
}

int main(int argc, char** argv)
{
    int cas;
    registerTestlibCmd(argc, argv);

    tcase = inf.readInt();
    for(cas=1;cas<=tcase;cas++)
    {
        n = inf.readInt(3,100000);
        for (int i=2;i<n;i++) {
            a[i] = inf.readInt(0,INF);
        }

        std_ans[1] = ans.readInt(-1,INF);
        as[1] = ouf.readInt(-1,INF);
        
        /*
        if (std_ans[1] == -1) {
            if (as[1] != -1) {
                quitf(_wa, "Case #%d: no solution and output a solution", cas);
            }
            continue;
        }
        */
        
        if (as[1] == -1) {
            if (std_ans[1] != -1) quitf(_wa, "Case #%d: output -1 when solution exists", cas);
            continue;
        }
        
        for (int i=2;i<=n;i++) {
            as[i] = ouf.readInt(0,INF);
            if (std_ans[1] != -1) std_ans[i] = ans.readInt(0,INF);
        }

        for (int i=2;i<n;i++) {
            int md = median(as[i-1],as[i],as[i+1]);
            if (md != a[i]) {
                quitf(_wa, "Case #%d: at index [%d,%d,%d], get median %d, %d excepted", cas, i-1,i,i+1, md, a[i]);
            }
        }
        
        if (std_ans[1] == -1) quitf(_fail, "Case #%d: participant found solution but jury does not", cas);
    }

    quitf(_ok, "%d cases",tcase);
}
