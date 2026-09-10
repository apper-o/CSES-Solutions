#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int solve(int n, vector<vector<int>> &arr)
{
    for(int i=1;i<=n;i++)
        for(int j=1+(i==1);j<=n;j++)
            if(arr[i][j] != 0)
                arr[i][j] = (arr[i][j-1] + arr[i-1][j]) % MOD;
    return arr[n][n];
}

int main() 
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n+1, vector<int>(n+1));
    char a;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>a;
            arr[i][j] = (a == '.');
        }
    auto res = solve(n, arr);
    cout<<res<<"\n";
    return 0;
}
