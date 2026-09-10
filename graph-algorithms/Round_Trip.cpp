#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 1e5+3;
const ll INF = 1e18+3;
const int X = 319;

int n, m;
vector<int> adj[MAXN];
vector<int> id(MAXN, -1);
vector<int> cycle;
vector<int> vis(MAXN);

void dfs(int v)
{
    vis[v]=1;
    id[v] = cycle.size();
    cycle.pb(v);
    for(int u : adj[v])
    {
        if(id[u]!=-1)
        {
            if(id[u]!=id[v]-1)
            {
                cout<<id[v]-id[u]+2<<"\n";
                for(int i=id[u];i<=id[v];i++)
                    cout<<cycle[i]<<" ";
                cout<<u<<"\n";
                exit(0);
            }
        }
        else if(!vis[u])
            dfs(u);
    }
    cycle.pop_back();
    id[v]=-1;
}

int main()
{
    cin>>n>>m;
    for(int i=0,a,b;i<m;i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    cout<<"IMPOSSIBLE";
    return 0;
}