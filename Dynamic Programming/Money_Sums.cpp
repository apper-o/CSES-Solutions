#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

vector<int> solve(const vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for(int i=0;i<n;i++)
        for(int j=sum;j>=arr[i];j--)
            dp[j] |= dp[j - arr[i]];
    vector<int> res;
    for(int i=1;i<=sum;i++)
        if(dp[i])  
            res.push_back(i);
    return res;
}

int main() 
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    auto res = solve(arr);
    cout<<res.size()<<"\n";
    for(int i : res)   
        cout<<i<<" ";
    return 0;
}
