// TASK : https://cses.fi/problemset/task/1694/
// Algorithm : Dinic's Maximum Flow
#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 503;
const ll INF = 1e18+3;
const int X = 319;
const int R = 1<<18;
const int MOD = 1e9+7;

int n, m;

struct pii{
    int v;
    ll c, f; // capacity, flow
};

vector<int> adj[MAXN];
vector<pii> e;
int lvl[MAXN];
int bg[MAXN];

bool bfs()
{
    memset(lvl,0,sizeof(lvl));
    memset(bg,0,sizeof(bg));
    queue<int> q;
    q.push(1);
    lvl[1]=1;
    while(q.size())
    {
        auto v = q.front();
        q.pop();
        for(int i : adj[v])
        {
            auto [u, c, f] = e[i]; 
            if(lvl[u] || c==f)
                continue;
            lvl[u] = lvl[v] + 1;
            q.push(u);
        }
    }
    return lvl[n];
}

int dfs(int v, ll flow)
{
    if(v==n)
        return flow;
    for(int j=bg[v];j<adj[v].size();bg[v]=++j)
    {
        int i = adj[v][j];
        auto [u, c, f] = e[i];
        if(c==f || lvl[u]!=lvl[v]+1)
            continue;
        int tmp = dfs(u, min(flow, c-f));
        if(tmp)
        {
            e[i].f += tmp;
            e[i^1].f -= tmp;
            return tmp;
        }
    }
    return 0;
}

void solve()
{
    ll res = 0;
    while(bfs())
    {
        ll tmp = 0;
        while(tmp = dfs(1, INF))
            res+=tmp;
    }
    cout<<res<<"\n";
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0,a,b,c;i<m;i++)
    {
        cin>>a>>b>>c;
        e.pb({b, c, 0});
        e.pb({a, 0, 0});
        adj[a].pb(2*i);
        adj[b].pb(2*i+1);
    }
    solve();
    return 0;
}