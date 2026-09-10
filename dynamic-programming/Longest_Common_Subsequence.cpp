#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

vector<int> solve(const vector<int> &a, const vector<int> &b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = a[0] == b[0];
    for(int i=1;i<n;i++)
        dp[i][0] = dp[i-1][0] || (a[i] == b[0]);
    for(int i=1;i<m;i++)
        dp[0][i] = dp[0][i-1] || (a[0] == b[i]);
    for(int i=1;i<n;i++) 
    {
        for(int j=1;j<m;j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    vector<int> res;
    int y = n - 1, x = m - 1;
    while(y>=0 && x>=0 && dp[y][x] > 0)
    {
        while(y>0 && dp[y-1][x] == dp[y][x])
                y--;
        while(x>0 && dp[y][x-1] == dp[y][x])
            x--;
        res.push_back(a[y]);
        x--;
        y--;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() 
{
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    auto res = solve(a, b);
    cout<<res.size()<<"\n";
    for(int i : res)
        cout<<i<<" ";
    return 0;
}
