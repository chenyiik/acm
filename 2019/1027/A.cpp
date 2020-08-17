#include<bits/stdc++.h>
using namespace std;
struct raw
{
    int val,s;
    bool operator<(const raw& b) const
    {
        return val<b.val;
    }
};
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    static raw a[100005];
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        cout << n - x + 1 << " \n"[i == n];
    }
    return 0;
}