#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int solve(int n)
{
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int j=0;j<=n;j++)
        for(int i=1;i<=6 && i+j<=n;i++)
            dp[j+i] = (dp[j+i] + dp[j]) % MOD;
    return dp[n];
}

int main() 
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    auto res = solve(n);
    cout<<res<<"\n";
    return 0;
}
