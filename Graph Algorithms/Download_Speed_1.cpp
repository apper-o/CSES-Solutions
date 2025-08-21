// TASK : https://cses.fi/problemset/task/1694
// Algorithm : Edmonds-Karp Maximum Flow
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

struct pii{
    int v;
    ll c, f;
};

int n, m;
vector<int> adj[MAXN];
vector<pii> edges;
int p[MAXN];

int bfs()
{
    memset(p,-1,sizeof(p));
    queue<pair<int, ll>> q;
    q.push({1, INF});
    while(q.size())
    {
        auto [v, flow] = q.front();
        q.pop();
        for(int i : adj[v])
        {
            auto [u, c, f] = edges[i];
            if(c==f || p[u]!=-1)
                continue;
            p[u]=i;
            if(u==n)
                return min(c-f, flow);
            q.push({u, min(c-f, flow)});
        }
    }
    return 0;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0,a,b,c;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].pb(edges.size());
        edges.pb({b, c, 0});
        adj[b].pb(edges.size());
        edges.pb({a, 0, 0});
    }
    ll flow, res=0;
    while(flow = bfs())
    {
        int i = p[n];
        while(1)
        {
            edges[i].f+=flow;
            edges[i^1].f-=flow;
            if(edges[i^1].v==1)
                break;
            i = p[edges[i^1].v];
        
        }
        res += flow;
    }
    cout<<res<<"\n";
    
    return 0;
}
