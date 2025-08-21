#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 2*1e5+3;
const ll INF = 1e18+3;
const int X = 19;
const int R = 1<<18;
const int MOD = 1e9+7;

struct edge{
    int a, b, c;
};

int n, m;
vector<int> p(MAXN);
vector<int> sz(MAXN);
vector<edge> e;

int get(int v)
{
    return (p[v]==v ? v : p[v]=get(p[v]));
}

void unite(int a, int b)
{
    if(sz[a]<sz[b])
        swap(a, b);
    sz[a]+=sz[b]+1;
    p[b]=a;
}


int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    e.resize(m);    
    for(int i=0,a,b,c;i<m;i++)
        cin>>e[i].a>>e[i].b>>e[i].c;
    sort(e.begin(), e.end(), [] (edge a, edge b) {
        return a.c < b.c;
    });
    for(int i=1;i<=n;i++)
        p[i]=i;
    ll res = 0;
    int cnt = 1;
    for(int i=0;cnt<n && i<m;i++)
    { 
        auto [a, b, c] = e[i];
        a=get(a), b=get(b);
        if(a==b)
            continue;
        cnt++;
        unite(a, b);
        res+=c;
    }
    if(cnt==n)
        cout<<res;
    else
        cout<<"IMPOSSIBLE";
}