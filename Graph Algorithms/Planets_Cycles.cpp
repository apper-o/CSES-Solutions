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
 
int n;
vector<int> adj[MAXN];
vector<int> id(MAXN); // in a component
vector<int> dep(MAXN);
vector<int> anc(MAXN);
vector<int> sz(MAXN);
int cnt=0;
 
 
void dfs(int v)
{
    for(int u : adj[v])
    {
        if(!sz[u] && !id[u])
        {
            dep[u]=dep[v]+1;
            sz[u]=sz[v];
            dfs(u);
        }
    }
}
 
int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>anc[i];
    for(int i=1;i<=n;i++)
        adj[anc[i]].pb(i);
    for(int i=1;i<=n;i++)
    {
        if(sz[i])
            continue;
        int v = i;
        id[v]=1;
        vector<int> c={v};
        while(!id[anc[v]])
        {
            id[anc[v]] = id[v]+1;
            v=anc[v];
            c.pb(v);
        }
        v = anc[v];
        for(int j=0;j<id[v]-1;j++)
            id[c[j]]=0;
        for(int j=id[v]-1;j<c.size();j++)
        {
            dep[c[j]] = 1;
            sz[c[j]] = c.size()-id[v]+1;
            dfs(c[j]);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<dep[i]-1+sz[i]<<" ";
    
    return 0;
}