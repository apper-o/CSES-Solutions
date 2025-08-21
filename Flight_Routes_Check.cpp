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
vector<int> vis(MAXN);
vector<int> order;
vector<int> scc[MAXN];
int cnt=0;

void dfs(int v)
{
    vis[v]=1;
    for(int u : adj[v])
        if(!vis[u])
            dfs(u);
    order.pb(v);
}

void dfs2(int v)
{
    vis[v]=0;
    scc[cnt].pb(v);
    for(int u : adjt[v])
        if(vis[u])
            dfs2(u);
}

void solve()
{
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    for(int i=n-1;i>=0;i--)
    {
        int v = order[i];
        if(vis[v])
        {
            dfs2(v);
            cnt++;
        }
    }
    if(cnt==1)
        cout<<"YES\n";
    else
    {
        cout<<"NO\n";
        cout<<scc[1][0]<<" "<<scc[0][0]<<"\n";
    }

}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0,a,b;i<m;i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adjt[b].pb(a);
    }
    solve();
    return 0;
}