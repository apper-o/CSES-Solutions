#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

pair<int, int> compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first == b.first)
        return (a.second > b.second ? a : b);
    return (a.first < b.first ? a : b);
} 

pair<int, int> get(pair<int, int> a, int weight, int x)
{
    if(a.second >= weight)
        return {a.first, a.second - weight};
    return {a.first + 1, x - weight};
}

int solve(int n, int x, const vector<int> weights)
{
    vector<pair<int, int>> dp(1 << n, {INF, -INF});
    for(int i=0;i<n;i++)
        dp[1 << i] = {1, x - weights[i]};
    for(int mask=0;mask<1<<n;mask++)
        for(int i=0;1<<i<=mask;i++)
            if(mask & (1<<i))
                dp[mask] = compare(dp[mask], get(dp[mask^(1<<i)], weights[i], x));
    return dp[(1<<n) - 1].first;
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin>>n>>x;
    vector<int> weights(n);
    for(int i=0;i<n;i++)
        cin>>weights[i];
    auto res = solve(n, x, weights);
    cout<<res<<"\n";

    return 0;
}
