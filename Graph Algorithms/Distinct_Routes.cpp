#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 2*503;//4*1e5+3;
const ll INF = 1e9+3;
const int X = 319;
const int R = 1<<18;
const int MOD = 1e9+7;


struct pii{
    int v, f, c;
};

int n, m, k;
vector<int> adj[MAXN];
vector<pii> e; 
vector<int> vert;
int lvl[MAXN];
int bg[MAXN];

bool bfs()
{
    memset(lvl,0,sizeof(lvl));
    memset(bg,0,sizeof(bg));
    queue<int> q;
    q.push(1);
    lvl[1]=1;
    while(q.size())
    {
        int v = q.front();
        q.pop();
        for(int i : adj[v])
        {
            auto [u, f, c] = e[i];
            if(f==c || lvl[u])
                continue;
            lvl[u]=lvl[v]+1;
            q.push(u);
        }
    }
    return lvl[n];
}


int dfs(int v)
{
    if(v==n)
        return 1;
    for(;bg[v]<adj[v].size();bg[v]++)
    {
        int i = adj[v][bg[v]];
        auto [u, f, c] = e[i];
        if(f==c || lvl[u]!=lvl[v]+1)
            continue;
        if(dfs(u))
        {
            e[i].f++;
            e[i^1].f--;
            return 1;
        }
    }
    return 0;
}

void get(int v)
{
    vert.pb(v);
    if(v==n)
        return;
    for(int i : adj[v])
    {
        if(i&1)
            continue;
        auto [u, f, c] = e[i];
        if(f==1 && e[i+1].f==-1)
        {
            e[i].f--;
            get(u);
            break;
        }
    }
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0,a,b;i<m;i++)
    {
        cin>>a>>b;
        adj[a].pb(2*i);
        adj[b].pb(2*i+1);
        e.pb({b, 0, 1});
        e.pb({a, 0, 0});
    }
    int res = 0;
    while(bfs())
    {
        int tmp;
        while(tmp = dfs(1))
            res += tmp;
    }
    cout<<res<<"\n";
    for(int i=0;i<res;i++)
    {
        vert.clear();
        get(1);
        cout<<vert.size()<<"\n";
        for(int v : vert)
            cout<<v<<" ";
        cout<<"\n";
    }
        
    return 0;
}