#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional<of,long long,signed>::type;
using idouble=conditional<of,long double,double>::type;
constexpr bool dbg=!true;
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
    if(!dbg) ios::sync_with_stdio(0),cin.tie(0);
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
template<iint precision=-1,typename T,typename... U>
void println(T&&arg,U&&... args)
{
    print<precision>(forward<T>(arg),forward<U>(args)...,'\n');
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
void doo()
{
    static stack<int> st;
    static deque<int> q;
    while (st.size()) st.pop();
    q.clear();
    static string s;read(s);
    bool succ=true;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='*') q.push_back(i);
        if (s[i]=='(') st.push(i);
        if (s[i]==')')
        {
            if (st.size()) st.pop();
            else if (q.size()) {s[q.front()]='(';q.pop_front();}
            else {succ=false;break;}
        }
    }
    while (st.size())
    {
        if (q.size() && q.back()>st.top())
        {
            s[q.back()]=')';
            st.pop();
            q.pop_back();
        }
        else
        {
            succ=false;break;
        }
    }
    if (!succ) println("No solution!");
    else{
        for (auto ch:s)
            if (set<char>({'(',')'}).count(ch))
                print(ch);
            print('\n');
    }
}
signed main()
{
    int t;read(t);
    while (t--) doo();
}