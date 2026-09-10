// TASK : https://cses.fi/problemset/task/1695
// Algorithm : Maximum Flow Minimum Cut
#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 503;//4*1e5+3;
const ll INF = 1e9+3;
const int X = 319;
const int R = 1<<18;
const int MOD = 1e9+7;

struct pii{
    int v;
    ll f, c;
};

int n, m;
vector<int> adj[MAXN];
int c[MAXN][MAXN]; // residual capacity
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
		for(int u : adj[v])
		{
			if(!c[v][u] || lvl[u])
				continue;
			lvl[u]=lvl[v]+1;
			q.push(u);
		}
	}
	return lvl[n];
}
 
int dfs(int v, int flow)
{
	if(v==n)
		return flow;
	for(;bg[v]<adj[v].size();bg[v]++)
	{	
        int i = bg[v];
		int u = adj[v][i];
		if(lvl[u]!=lvl[v]+1 || !c[v][u])
			continue;
		int tmp=dfs(u, min(flow, c[v][u]));
		if(tmp)
		{
			c[v][u]-=tmp;
			c[u][v]+=tmp;
			return tmp;
		}
	}
	return 0;
}
 
void solve()
{
    int res = 0;
	while(bfs())
	{
		int tmp=0;
		while(tmp=dfs(1, INF))
			res+=tmp;
	}
	bfs();
	cout<<res<<"\n";
	for(int v=1;v<=n;v++)
		if(lvl[v])
            for(int u : adj[v])
                if(!lvl[u])
                    cout<<v<<" "<<u<<"\n";
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
		c[a][b]++;
		c[b][a]++;
	}
	solve();
	return 0;
}