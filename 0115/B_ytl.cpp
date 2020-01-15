#include<cstdio>
#include<cstring>

#define M 200005
int A[M];
int las[M];
int S[M];
bool mark[M];

int main() {
    int i, n, k, tp = 0;
    memset(las, -1, sizeof(las));
    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        las[A[i]] = i;
    }
    S[tp++] = A[1];
    mark[A[1]] = 1;
    for (i = 2; i <= n; i++)
        if (!mark[A[i]])
    {
        while (tp > 0 && A[i] < S[tp - 1] && las[S[tp - 1]] > i) {
            mark[S[tp - 1]] = 0;
            tp--;
        }
            S[tp++] = A[i];
        mark[A[i]] = 1;
    }
    for (i = 0; i < tp; i++)
        printf("%d ", S[i]);
    puts("");
    return 0;
}