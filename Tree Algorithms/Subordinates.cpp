#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int dfs(int v, const vector<vector<int>> &adj, vector<int> &res)
{
    for(int u : adj[v])
        res[v] += dfs(u, adj, res);
    return res[v] + 1;
}


int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<int> res(n);
    vector<vector<int>> adj(n);
    for(int a,b=1;b<n;b++)
    {
        cin>>a;
        a--;
        adj[a].push_back(b);
    }
    dfs(0, adj, res);
    for(int i=0;i<n;i++)   
        cout<<res[i]<<" ";
    return 0;
}
