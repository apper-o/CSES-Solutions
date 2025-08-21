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
vector<int> col(MAXN, -1);

bool dfs(int v, int c)
{
    col[v] = c;
    for(int u : adj[v])
    {
        if(col[u]==-1)
            if(!dfs(u, c^1))
                return false;
        if(col[u]==col[v])
            return false;
    }
    return true;
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
    for(int v=1;v<=n;v++)
        if(col[v]==-1)
            if(!dfs(v, 0))
            {
                cout<<"IMPOSSIBLE";
                exit(0);
            }
    
    for(int i=1;i<=n;i++)
        cout<<col[i]+1<<" ";
    return 0;
}