#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional<of,long long,int>::type;
using idouble=conditional<of,long double,double>::type;
constexpr bool dbg=true;
template<iint buffersz>
inline char igetchar()
{
    static char buf[buffersz],*p1=buf,*p2=buf;
    return p1==p2 && (p2=(p1=buf)+fread(buf,1,buffersz,stdin),p1==p2)?EOF:*p1++;
}
template<iint buffersz,class T>
void read_one(T&x)
{
    static_assert(is_convertible<char,T>::value,"Not supporting type");
    x=0;
    iint f=0;
    char ch=igetchar<buffersz>();
    while(!isdigit(ch)) f|=(ch=='-'),ch=igetchar<buffersz>();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=igetchar<buffersz>();
    x=f?-x:x;
}
void readint()
{}
template<iint buffersz=dbg?1:(iint)1e4,typename T,typename... U>
void readint(T&arg,U&... args)
{
    static_assert(is_convertible<char,T>::value,"Not supporting type");
    read_one<buffersz>(arg);
    readint(args...);
}
bool firstrun=true;
decltype(cout.flags()) st;
void ifastios()
{
    if (!dbg) ios::sync_with_stdio(0),cin.tie(0);
    firstrun=false;
}
void print()
{}
template<iint precision=-1,typename T,typename... U>
void print(T&&arg,U&&... args)
{
    if(precision>=0)
    {
        st=cout.flags();
        cout.setf(ios::fixed);
        cout.precision(precision);
    }
    if(firstrun) ifastios();
    cout<<forward<T>(arg);
    print(args...);
    if(precision>=0) cout.flags(st);
}
void read()
{}
template<typename T,typename... U>
void read(T&arg,U&... args)
{
    if(firstrun) ifastios();
    cin>>arg;
    read(args...);
}
template<typename T>
void ipb(T&container)
{}
template<typename T,typename E,typename... U>
void ipb(vector<T>&container,E&&val,U&&... args)
{
    static_assert(is_convertible<E,T>::value,"Wrong value type");
    container.push_back(forward<E>(val));
    ipb(container,args...);
}
template<typename T,typename E,typename... U>
void ipb(list<T>&container,E&&val,U&&... args)
{
    static_assert(is_convertible<E,T>::value,"Wrong value type");
    container.push_back(forward<E>(val));
    ipb(container,args...);
}
template<typename T,typename E,typename... U>
void ipb(deque<T>&container,E&&val,U&&... args)
{
    static_assert(is_convertible<E,T>::value,"Wrong value type");
    container.push_back(forward<E>(val));
    ipb(container,args...);
}
template<typename T,typename E,typename... U>
void ipb(queue<T>&container,E&&val,U&&... args)
{
    static_assert(is_convertible<E,T>::value,"Wrong value type");
    container.push(forward<E>(val));
    ipb(container,args...);
}
template<typename T,typename E,typename... U>
void ipb(set<T>&container,E&&val,U&&... args)
{
    static_assert(is_convertible<E,T>::value,"Wrong value type");
    container.insert(forward<E>(val));
    ipb(container,args...);
}
struct node
{
    int val[3];
    int& operator[](int x) {return val[x];}
};
bool operator<(node a,node b)
{
    if (a[0]==b[0])
    {
        if (a[1]==b[1]) return a[2]<b[2];
        return a[1]<b[1];
    }
    return a[0]<b[0];
}
signed main()
{
    int T;read(T);
    while (T--)
    {
        static vector<node> vec;vec.clear();
        static node q[105];
        int n,m;read(n,m);
        int err=0;
        for (int i=0;i<m;i++)
        {
            int t;
            read(q[i][0],q[i][1],q[i][2],t);
            for (int j=0;j<3;j++)
            {
                if (q[i][j]==0) err=1;
                if ((!err||err==3) && (q[i][j]<-n||q[i][j]>n)) err=2;
                if (!err && abs(q[i][j])==abs(q[i][(j+1)%3])) err=3;
            }
        }
        vector<string> wr={"","INVALID: NULL RING","INVALID: RING MISSING","INVALID: RUNE CONTAINS A REPEATED RING"};
        if (err) {print(wr[err],'\n');continue;}
        sort(q,q+m);
        for (int i=0;i<m;i++)
        {
            vec.push_back(q[i]);
            while (i+1<m && q[i][0]==q[i+1][0] && q[i][1]==q[i+1][1] && q[i][2]==q[i+1][2]) i++;
        }
        bool flg=0;
        for (int st=0;st<(1<<n);st++)
        {
            int j;
            for (j=0;j<vec.size();j++)
            {
                int f=0;
                for (int k=0;k<3;k++)
                {
                    int w=vec[j][k];
                    int bb=abs(w);
                    bb--;
                    if ((st&(1<<bb))>0 && w<0) f++;
                    if ((st&(1<<bb))==0 && w>0) f++;
                }
                if (!(f-3)) break;
            }
            if (!(j-vec.size())) flg=1;
        }
        vector<string> tps={"RUNES SATISFIED!","RUNES UNSATISFIABLE! TRY ANOTHER GATE!"};
        print(tps[!flg],'\n');
    }

}