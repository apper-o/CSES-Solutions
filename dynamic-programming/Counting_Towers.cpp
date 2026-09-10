#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

vector<int> fill(int n)
{
    // dp[0] = 2 klocki, dp[1] = 1 klocek
    vector<vector<long long>> dp(2, vector<long long>(n + 1)); 
    dp[0][1] = dp[1][1] = 1;
    for(int i=2;i<=n;i++)
    {
        dp[0][i] = (4 * dp[0][i-1] + dp[1][i-1]) % MOD;
        dp[1][i] = (dp[0][i-1] + 2 * dp[1][i-1]) % MOD;
    } 
    vector<int> res(n + 1);
    for(int i=0;i<=n;i++)
        res[i] = (dp[0][i] + dp[1][i]) % MOD;
    return res;
}

int main() 
{
    int t;
    cin>>t;
    vector<int> arr(t);
    int n = 0;
    for(int i=0;i<t;i++)
        cin>>arr[i];
    for(int i=0;i<t;i++)
        n = max(n, arr[i]);
    auto res = fill(n);
    for(int i=0;i<t;i++)
        cout<<res[arr[i]]<<"\n";
    return 0;
}
