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

int n, q;
vector<int> adj[MAXN];

// cycle
vector<int> cycle(MAXN);
vector<int> id(MAXN);

// tree
vector<int> g(MAXN);
vector<int> dep(MAXN);
vector<int> top(MAXN);

int anc[X][MAXN];
int cnt=1;
int cnt2=0;
int C[MAXN];

void dfs(int v)
{
    g[v] = cnt;
    for(int u : adj[v])
    {
        if(!id[u] && !g[u])
        {
            dep[u]=dep[v]+1;
            top[u]=top[v];
            dfs(u);
        }
    }
}

int check(int a, int b)
{
    if(g[a]!=g[b] || dep[a] < dep[b])
        return -1;
    if(b==top[a])
        return dep[a]-dep[b];
    int res = 0;
    for(int x=X-1;x>=0;x--)
        if(dep[anc[x][a]]>=dep[b])
        {
            a=anc[x][a];
            res+=(1<<x);
        }
    return (a==b ? res : -1);
}


int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        dep[i]=1;
        cin>>anc[0][i];
        if(anc[0][i]==i)
            anc[0][i]=0;
        else
            adj[anc[0][i]].pb(i);
        
    }
    for(int x=1;x<X;x++)
        for(int i=1;i<=n;i++)
            anc[x][i]=anc[x-1][anc[x-1][i]];
    for(int i=1;i<=n;i++)
        if(anc[0][i]==0)
        {
            top[i]=i;
            dfs(i);
            cnt++;
        }
    for(int j=1;j<=n;j++)
    {
        if(anc[0][j]==j || id[j] || g[j])
            continue;
        cnt2++;
        vector<int> tmp;
        int v = j;
        id[v]=1;
        while(!id[anc[0][v]])
        {
            tmp.pb(v);
            id[anc[0][v]] = id[v]+1;
            v = anc[0][v];
        }
        tmp.pb(v);
        int it = 0;
        while(tmp[it]!=anc[0][v])
        {
            id[tmp[it]]=0;
            it++;
        }
        C[cnt2] = tmp.size()-it;
        for(int i=it;i<tmp.size();i++)
        {
            id[tmp[i]]=i-it+1;
            cycle[tmp[i]] = cnt2;
        }
        for(int i=it;i<tmp.size();i++) 
        {
            top[tmp[i]] = tmp[i];
            dfs(tmp[i]);
            cnt++;
        }
    }
    for(int i=0,a,b;i<q;i++)
    {
        cin>>a>>b;
        if(cycle[top[a]]!=cycle[top[b]])
            cout<<-1<<"\n";
        else if(id[b]==0)
            cout<<check(a, b)<<"\n";
        else
        {
            int add = (id[a] ? 0 : dep[a] - dep[top[a]]);
            a = top[a];
            cout<<add + (id[b] >= id[a] ? id[b]-id[a] : C[cycle[a]]-id[a]+id[b])<<"\n";
        }
    }


    return 0;
}