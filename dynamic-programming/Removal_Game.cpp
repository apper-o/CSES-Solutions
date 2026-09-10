#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

long long solve(const vector<int> &arr)
{
    int n = arr.size();
    vector<vector<long long>> dp(n, vector<long long>(n));
    for(int i=0;i<n;i++)
        dp[i][i] = arr[i];
    for(int i=0;i+1<n;i++)
        dp[i][i+1] = max(arr[i], arr[i+1]);
    for(int i=2;i<n;i++)
        for(int j=0;j+i<n;j++)
            dp[j][j+i] = max(arr[j] + min(dp[j+2][j+i], dp[j+1][j+i-1]), arr[j+i] + min(dp[j+1][j+i-1], dp[j][j+i-2]));
    return dp[0][n-1];
}

int main() 
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    auto res = solve(arr);
    cout<<res<<"\n";
    return 0;
}
