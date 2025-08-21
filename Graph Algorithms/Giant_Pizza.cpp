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
vector<int> adj[MAXN]; // 2*v = v | 2*v+1 = not v  
vector<int> adjt[MAXN];
vector<int> scc(MAXN);
vector<int> vis(MAXN);
vector<int> order;
vector<char> ans(MAXN);
int t=1;

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
    scc[v]=t;
    for(int u : adjt[v])
        if(!scc[u])
            dfs2(u);
}

void solve()
{
    for(int i=1;i<=2*n;i++)
        if(!vis[i])
            dfs(i);
    for(int i=2*n-1;i>=0;i--)
    {
        int v = order[i];
        if(!scc[v])
        {
            dfs2(v);
            t++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(scc[2*i]==scc[2*i+1])
        {
            cout<<"IMPOSSIBLE\n";
            return;
        }
        ans[i] = (scc[2*i] < scc[2*i+1] ? '-' : '+');
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";

}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>m>>n;
    for(int i=0,a,b;i<m;i++)
    {
        char x, y;
        cin>>x>>a>>y>>b;
        adj[2*a+(x=='+')].pb(2*b+(y=='-'));
        adj[2*b+(y=='+')].pb(2*a+(x=='-'));
        adjt[2*b+(y=='-')].pb(2*a+(x=='+'));
        adjt[2*a+(x=='-')].pb(2*b+(y=='+'));
    }
    solve();
    return 0;
}