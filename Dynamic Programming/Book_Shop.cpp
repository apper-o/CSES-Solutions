#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int solve(int n, int x, const vector<int> &price, const vector<int> &pages)
{
    vector<int> dp(x+1, -1);
    dp[0] = 0;
    for(int i=0;i<n;i++)
        for(int j=x;j>=price[i];j--)
            if(dp[j - price[i]] >= 0)
                dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
    int res = 0;
    for(int i=1;i<=x;i++)
        res = max(res, dp[i]);
    return res;
}

int main() 
{
    int n, x;
    cin>>n>>x;
    vector<int> price(n), pages(n);
    for(int i=0;i<n;i++)
        cin>>price[i];
    for(int i=0;i<n;i++)
        cin>>pages[i];
    auto res = solve(n, x, price, pages);
    cout<<res<<"\n";
    return 0;
}
