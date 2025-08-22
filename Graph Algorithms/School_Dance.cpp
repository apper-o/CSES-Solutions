// TASK : https://cses.fi/problemset/task/1696/
// Algorithm : Graph Matching
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


int n, m, k;
vector<int> adj[MAXN];
vector<int> match(MAXN);
vector<int> lvl(MAXN);

bool bfs()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(!match[i])
        {
            q.push(i);
            lvl[i]=1;
        }
        else
            lvl[i]=0;
    }
    lvl[0]=0;
    while(q.size())
    {
        auto v = q.front();
        q.pop();
        for(int u : adj[v])
        {
            if(!lvl[match[u]])
            {
                lvl[match[u]] = lvl[v] + 1;
                if(!match[u])
                    return true;
                q.push(match[u]);
            }
        }
    }
    return false;
}

bool dfs(int v)
{
    if(v==0)
        return true;
    for(int u : adj[v])
    {
        if(lvl[v]+1==lvl[match[u]] && dfs(match[u]))
        {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    lvl[v]=-1;
    return false;
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=0,a,b;i<k;i++)
	{
		cin>>a>>b;
		adj[a].pb(b+n);
		adj[b+n].pb(a);
    }
    int res = 0;
    while(bfs())
        for(int i=1;i<=n;i++)
            if(!match[i] && dfs(i))
                res++;
    cout<<res<<"\n";
    for(int i=1;i<=n;i++)
        if(match[i])
            cout<<i<<" "<<match[i]-n<<"\n";
	return 0;
}