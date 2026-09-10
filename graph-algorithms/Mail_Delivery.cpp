#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//-------------------------code-------------------------//
const int MAXN = 2*1e5+3;
 
int n, m;
vector<pair<int, int>> adj[MAXN];
vector<int> path;
vector<int> vis(MAXN);
 
#define no {cout<<"IMPOSSIBLE\n"; return 0;}
 
void dfs(int v)
{
	for(int i=adj[v].size()-1;i>=0;i--)
	{
		if(i>=adj[v].size())
		{
			i=adj[v].size();
			continue;
		}
		auto [u, w] = adj[v][i];
		swap(adj[v][i], adj[v].back());
		adj[v].pop_back();
		if(!vis[w])	
		{
			vis[w]=1;
			dfs(u);
		}
	}
	if(adj[v].empty())
		path.pb(v);	
}
 
 
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0,a,b;i<m;i++)
	{
		cin>>a>>b;
		adj[a].pb({b, i});
		adj[b].pb({a, i});
	}
	for(int i=1;i<=n;i++)	
		if(adj[i].size()%2)
			no
	dfs(1);
	// checks whether the graph is connected
	if((int)path.size()<m+1)
        no
    // prints a Eulerian Cycle
	reverse(path.begin(), path.end());
	for(auto v : path)
		cout<<v<<" ";
	return 0;
}