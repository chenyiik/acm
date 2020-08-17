#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        string s;
        cin>>s;
        for (char &c : s)
        {
            if (c == 'y')
                continue;
            else if (c == 'z')
                c = 'b';
            break;
        }
        cout<<s<<endl;
    }
    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> c60af5c3ebf4bc0dfa120787215675ab9379400c
