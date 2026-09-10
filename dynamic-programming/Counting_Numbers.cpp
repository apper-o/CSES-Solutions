#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

long long dp[11][20][2][2]; // [last digit][digit count][limit][leading_zero]

long long solve(int last_dig, int dig_cnt, bool lim, bool leading_zero, string number)
{
    if(dig_cnt == number.size())
        return 1;
    if(dp[last_dig][dig_cnt][lim][leading_zero] != -1)
        return dp[last_dig][dig_cnt][lim][leading_zero];
    long long res = 0;
    int upper = (lim ? number[dig_cnt] - '0' : 9);
    for(int i=0;i<=upper;i++)
    {
        if(leading_zero)
        {  
            if(i == 0)
                res += solve(10, dig_cnt + 1, lim & (i == upper), 1, number);
            else
                res += solve(i, dig_cnt + 1, lim & (i == upper), 0, number);
        }
        else if(i != last_dig)
            res += solve(i, dig_cnt + 1, lim & (i == upper), 0, number);
    }
    return dp[last_dig][dig_cnt][lim][leading_zero] = res;
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp,-1,sizeof(dp));
    long long a, b;
    cin>>a>>b;
    auto res = solve(10, 0, 1, 1, to_string(b));
    if(a > 0)
    {
        memset(dp, -1, sizeof(dp));
        res -= solve(10, 0, 1, 1, to_string(a-1));
    }
    cout<<res<<"\n";
    return 0;
}
