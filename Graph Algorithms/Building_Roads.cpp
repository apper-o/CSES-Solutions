#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 1e5+3;
const int INF = 1e9+3;
const int X = 319;


int n, m;
vector<int> adj[MAXN];
vector<int> vis(MAXN);

void dfs(int v)
{
    vis[v]=1;
    for(int u : adj[v])
        if(!vis[u])
            dfs(u);
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0,a,b;i<m;i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<pair<int, int>> res;
    dfs(1);
    for(int i=2;i<=n;i++)
        if(!vis[i])
        {
            res.pb({1, i});
            dfs(i);
        }
    cout<<res.size()<<"\n";
    for(auto [a, b] : res)
        cout<<a<<" "<<b<<"\n";
    return 0;
}
