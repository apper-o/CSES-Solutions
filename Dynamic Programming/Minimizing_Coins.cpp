#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int solve(int n, int x, const vector<int> &arr)
{
    vector<int> dp(x+1, INF);
    dp[0] = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j+arr[i]<=x;j++)
            dp[j + arr[i]] = min(dp[j + arr[i]], dp[j] + 1);
    return (dp[x] == INF ? -1 : dp[x]);
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
