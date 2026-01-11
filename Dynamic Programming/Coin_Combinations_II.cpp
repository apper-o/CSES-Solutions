#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int solve(int n, int x, const vector<int> &arr)
{
    vector<int> dp(x+1);
    dp[0] = 1;
    for(int j=0;j<n;j++)
        for(int i=0;i+arr[j]<=x;i++)
            dp[i + arr[j]] = (dp[i + arr[j]] + dp[i]) % MOD;
    return dp[x];
}

int main() 
{
    int n, x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    auto res = solve(n, x, arr);
    cout<<res<<"\n";
    return 0;
}
