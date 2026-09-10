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
 
int n, m;
vector<int> adj[MAXN];
vector<int> adjt[MAXN];
vector<ll> val(MAXN);
vector<ll> val2(MAXN);
vector<int> vis(MAXN);
vector<int> scc[MAXN];
vector<int> id(MAXN);
vector<int> c;
int t=0;

void dfs(int v)
{
    vis[v] = 1;
    for(int u : adj[v]) 
        if(!vis[u])
            dfs(u);
    c.pb(v);
}

void dfs2(int v)
{
    scc[t].pb(v);
    id[v]=t;
    vis[v] = 0;
    for(int u : adjt[v])
        if(vis[u])
            dfs2(u);
}

ll get(int i)
{
    vis[i]=1;
    ll res = 0;
    for(int v : scc[i])
        for(int u : adj[v])
        {
            if(!vis[id[u]])
                res = max(res, get(id[u]));
            else if(id[u]!=i)
                res = max(res, val2[id[u]]);
        }
    return val2[i] = res + val2[i];
}

void solve()
{
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    for(int i=n-1;i>=0;i--)
        if(vis[c[i]])
        {
            dfs2(c[i]);
            t++;
        }
    for(int i=0;i<t;i++)
        for(int v : scc[i])
            val2[i]+=val[v];
    ll res = 0;
    for(int i=0;i<t;i++)
        if(!vis[i])
            res = max(res, get(i));
    cout<<res<<"\n";
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)  
        cin>>val[i];
    for(int i=0,a,b;i<m;i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adjt[b].pb(a);
    }
    solve();
    return 0;
}