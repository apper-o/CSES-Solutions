#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int expo(int a, int b)
{
    int res = 1;
    while(b)
    {
        if(b % 2)  
            res = ((long long)res * a) % MOD;
        a = ((long long)a * a) % MOD;
        b/=2;
    }
    return res;
}

int inv(int a)
{
    return expo(a, MOD - 2);
}

int solve(int n)
{
    if(n*(n+1)/2 % 2)
        return 0;
    int sum = n*(n+1)/4;
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for(int i=1;i<=n;i++)
        for(int j=sum;j>=i;j--)
            dp[j] = (dp[j] + dp[j-i]) % MOD;
    return (long long)dp[sum] * inv(2) % MOD;
}

int main() 
{
    int n;
    cin>>n;
    auto res = solve(n);
    cout<<res<<"\n";
    return 0;
}
