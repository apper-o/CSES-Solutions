#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 2*1e5+3;
const ll INF = 1e18+3;
const int X = 319;
const int R = 1<<18;
 
 
int n, m;
vector<int> adj[MAXN];
vector<int> vis(MAXN);
vector<int> on(MAXN);
vector<int> vert={-1};
 
void dfs(int v)
{   
    vis[v]=1;
    on[v]=vert.size();
    vert.pb(v);
    for(int u : adj[v])
    {
        if(!vis[u])
            dfs(u);
        else if(on[u])
        {
            cout<<vert.size()-on[u]+1<<"\n";
            for(int i=on[u];i<vert.size();i++)
                cout<<vert[i]<<" ";
            cout<<u;
            exit(0);
        }
    }
    on[v]=0;
    vert.pop_back();
}
 
void solve()
{
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    cout<<"IMPOSSIBLE";
}
 
int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0,a,b;i<m;i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
    }
    solve();
    return 0;
}