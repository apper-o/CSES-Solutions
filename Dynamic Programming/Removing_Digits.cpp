#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int solve(int n)
{
    int res = 0;
    while(n)
    {
        res++;
        int x = n;
        int mx = 0;
        while(x)
        {
            mx = max(mx, x % 10);
            x /= 10;
        }
        n -= mx;
    }
    return res;
}

int main() 
{
    int n;
    cin>>n;
    auto res = solve(n);
    cout<<res<<"\n";
    return 0;
}
