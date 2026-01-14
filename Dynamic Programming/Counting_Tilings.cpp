#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

void get(int x, int y, int n, int m, int current_mask, int new_mask, vector<vector<int>> &dp)
{
    if(y == n)
    {
        dp[new_mask][x + 1] = (dp[new_mask][x + 1] + dp[current_mask][x]) % MOD;
        return;
    }
    if(current_mask & (1 << y))
        get(x, y + 1, n, m, current_mask, new_mask, dp);
    else
    {
        get(x, y + 1, n, m, current_mask, new_mask + (1 << y), dp);
        if(y + 1 < n && (current_mask & (1 << (y + 1))) == 0)
            get(x, y + 2, n, m, current_mask, new_mask, dp);
    }
}

int solve(int n, int m)
{
    vector<vector<int>> dp(1 << (n+1), vector<int>(m+1));
    dp[0][0] = 1;
    for(int x=0;x<m;x++)
        for(int mask=0;mask<(1<<n);mask++)
            get(x, 0, n, m, mask, 0, dp);
    return dp[0][m];
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin>>n>>m;
    auto res = solve(n, m);
    cout<<res<<"\n";
    return 0;
}
