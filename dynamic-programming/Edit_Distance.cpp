#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int solve(const string &s, const string &t)
{
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for(int i=1;i<=n;i++)
        dp[i][0] = i;
    for(int i=1;i<=m;i++)
        dp[0][i] = i;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            if(s[i-1] == t[j-1])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
        }
        cout<<"\n";
    }
    return dp[n][m];
}

int main() 
{
    string s, t;
    cin>>s>>t;
    auto res = solve(s, t);
    cout<<res<<"\n";
    return 0;
}
