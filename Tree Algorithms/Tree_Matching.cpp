#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;


void dfs(int v, int p, const vector<vector<int>> &adj, vector<vector<int>> &dp)
{
    int mx = 0;
    int sum = 0;
    for(int u : adj[v])
    {
        if(u != p)
        {
            dfs(u, v, adj, dp);
            int score = max(dp[u][0], dp[u][1]);
            sum += score;
            if(dp[u][0] - score + 1 > mx)
                mx = dp[u][0] - score + 1;
        }
    }
    dp[v][0] = dp[v][1] = sum;
    if(mx > 0)
        dp[v][1] += mx;
}


int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    // dp[v][0] = not matched or started match | dp[v][1] = completed match
    vector<vector<int>> dp(n, vector<int>(2));
    vector<vector<int>> adj(n);
    for(int i=0,a,b;i<n-1;i++)
    {
        cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, adj, dp);
    cout<<max(dp[0][0], dp[0][1]);
    return 0;
}
