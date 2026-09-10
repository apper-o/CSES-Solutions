#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

struct pii
{
    int a, b;
    int val;
};

long long solve(int n, vector<pii> &arr)
{
    sort(arr.begin(), arr.end(), [] (const auto &a, const auto &b) 
    {
        return a.b < b.b;
    });
    // dp[i] = maximal sum at index i (prefix)
    vector<long long> dp(n + 1);
    for(int i=1;i<=n;i++)
    {
        int lo = 0, hi = i - 1;
        while(lo < hi)
        {
            int mid = lo + (hi - lo + 1) / 2;
            if(arr[mid].b < arr[i].a)
                lo = mid;
            else
                hi = mid - 1;
        }
        dp[i] = max(dp[i-1], dp[lo] + arr[i].val);
    }
    return dp[n];
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<pii> arr(n + 1);
    for(int i=1;i<=n;i++)
        cin>>arr[i].a>>arr[i].b>>arr[i].val;
    auto res = solve(n, arr);
    cout<<res<<"\n";
    return 0;
}
