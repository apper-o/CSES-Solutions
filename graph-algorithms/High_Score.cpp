#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 2*1e5+3;
const ll INF = 1e18+3;
const int X = 319;

struct pii{
    int v; ll w;
};

struct tpl{
    int a, b, c;
};

int n, m;
vector<int> adj[MAXN];
vector<int> adjt[MAXN];
vector<ll> dist(MAXN, INF);
vector<int> cnt(MAXN);
vector<int> on(MAXN);
vector<int> off(MAXN, 1);
vector<tpl> edges;

void dfs(int v)
{
    for(int id : adjt[v])
    {
        if(off[id]==0)
            continue;
        int u = edges[id].a;
        off[id]=0;
        dfs(u);
    }
}

void solve()
{  
    dfs(n);
    dist[1]=0;
    queue<int> q;
    q.push(1);
    while(q.size())
    {
        int v = q.front();
        q.pop();
        on[v]=0;
        cnt[v]++;
        if(cnt[v]>=n)
        {
            cout<<-1<<"\n";
            return;
        }
        for(int id : adj[v])
        {
            if(off[id])
                continue;
            int u = edges[id].b; ll w = edges[id].c;
            if(dist[u] > dist[v] + w)
            {
                dist[u] = dist[v] + w;
                if(!on[u])
                {
                    q.push(u);
                    on[u]=1;
                }
            }
        }

    }
    cout<<-dist[n]<<"\n";
}


int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    if(n==1)
    {  
        ll res = -INF;
        for(ll i=0,a,b,c;i<m;i++)
        {
            cin>>a>>b>>c;
            res = max(res, c);
        }
        cout<<(res>0 ? -1 : 0)<<"\n";
        return 0;
    }
    for(int i=0,a,b,c;i<m;i++)
    {
        cin>>a>>b>>c;
        edges.pb({a, b, -c});
        adj[a].pb(i);
        adjt[b].pb(i);
    }
    solve();
    return 0;
}
