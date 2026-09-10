#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// .first returns the maximum diameter starting at vertex v | .second id of the last vertex
pair<int, int> dfs(int v, int p, const vector<vector<int>> &adj)
{
    pair<int, int> res = {0, v};
    for(int u : adj[v])
        if(u != p)
            res = max(res, dfs(u, v, adj));
    return {res.first + 1, res.second};
}

int solve(int n, const vector<vector<int>> &adj)
{
    if(n <= 1)
        return 0;
    return dfs(dfs(1, n, adj).second, n, adj).first - 1; 
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0,a,b;i<n-1;i++)
    {
        cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    auto res = solve(n, adj);
    cout<<res<<"\n";
    return 0;
}
