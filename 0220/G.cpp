#include<bits/stdc++.h>
using namespace std;
struct moving
{
    int dx,dy;
    moving(){dx=dy=0;}
    moving(char ch)
    {
        dx=dy=0;
        if (ch=='R') dx=1;
        if (ch=='L') dx=-1;
        if (ch=='U') dy=1;
        if (ch=='D') dy=-1;
    }
};
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string route;
    cin>>route;
    vector<moving> mov;
    for (auto ch:route) mov.push_back(moving(ch));
    static bool board[405][405];
    int tries=500;
    while (tries--)
    {
        static default_random_engine rng;
        int all=0;
        static vector<int> resx,resy;
        resx.clear(),resy.clear();
        for (int i=0;i<=400;i++)
            for (int j=0;j<=400;j++)
            {
                board[i][j]=(i==0||j==0||i==400||j==400)||(double(rng())/(double(rng.max()-rng.min()))<0.02);
                if (board[i][j]) resx.push_back(i),resy.push_back(j),all++;
            }

        if (all>int(1e4)) continue;
        int startx=0,starty=0;
        while (board[startx][starty]) startx=rng()%400,starty=rng()%400;
        bool ok=true;
        int x=startx,y=starty;
        for (auto mv:mov)
        {
            if (board[x+mv.dx][y+mv.dy]) {ok=false;break;}
            while (!board[x+mv.dx][y+mv.dy]) {x+=mv.dx,y+=mv.dy;}
        }
        if (!ok) continue;
        int termx=x,termy=y;
        x=startx,y=starty;
        for (auto mv:mov)
        {
            bool fail=false;
            while (!board[x+mv.dx][y+mv.dy])
            {
                if (x==termx && y==termy) {ok=false;fail=true;break;}
                x+=mv.dx,y+=mv.dy;
            }
            if (fail) break;
        }
        if (!ok) continue;
        cout<<(startx-termx)<<" "<<(starty-termy)<<endl;
        cout<<all<<endl;
        for (int i=0;i<all;i++) cout<<resx[i]-termx<<" "<<resy[i]-termy<<endl;
        return 0;
    }
    cout<<"impossible"<<endl;
}