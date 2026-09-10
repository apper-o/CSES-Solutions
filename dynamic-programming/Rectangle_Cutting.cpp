#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int solve(int a, int b)
{
    vector<vector<int>> dp(a+1, vector<int>(b+1, INF));
    for(int i=0;i<=min(a,b);i++)
        dp[i][i] = 0;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            for(int k=1;k<=(j+1)/2;k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            for(int k=1;k<=(i+1)/2;k++)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
        }
    }
    return dp[a][b];
}

int main() 
{
    int a, b;
    cin>>a>>b;
    auto res = solve(a, b);
    cout<<res<<"\n";
    return 0;
}
