#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int solve(int n, int m, const vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(m+2));
    if(arr[0] != 0)
        dp[0][arr[0]] = 1;
    else
        for(int i=1;i<=m;i++)
            dp[0][i] = 1;
    for(int i=1;i<n;i++)
    {
        if(arr[i] != 0)
            dp[i][arr[i]] = ((long long)dp[i-1][arr[i] - 1] + dp[i-1][arr[i]] + dp[i-1][arr[i] + 1]) % MOD;
        else
            for(int j=1;j<=m;j++)
                dp[i][j] = ((long long)dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
    }
    int res = 0;
    for(int i=1;i<=m;i++)
        res = (res + dp[n-1][i]) % MOD;
    return res;
}

int main() 
{
    int n, m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    auto res = solve(n, m, arr);
    cout<<res<<"\n";
    return 0;
}
