#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

struct SegmentTree
{
    vector<int> v;
    int size = 1;

    SegmentTree(int n)
    {
        while(size <= n)
            size *= 2;
        v.resize(2*size);
    }

    SegmentTree(vector<int> arr) : SegmentTree(arr.size())
    {
        for(int i=0;i<arr.size();i++)
            v[i + size] = arr[i];
        for(int i=size-1;i>0;i--)
            v[i] = max(v[2*i], v[2*i+1]);
    }

    int query(int a, int b, vector<int> &arr)
    {
        int res = 0;
        a += size-1;
        b += size-1;
        res = max(v[a], v[b]);
        while(a/2 != b/2)
        {
            if(a % 2 == 0)
                res = max(res, v[a + 1]);
            if(b % 2 == 1)
                res = max(res, v[b - 1]);
            a /= 2;
            b /= 2;
        }
        return res;
    }
};

int dfs(int l, int r, SegmentTree &tree, map<pair<int, int>, int> &dp)
{
    if (l > r) 
        return 0;
    if(l == r)
        return 1;
    if(dp[{l, r}])
        return dp[{l, r}];
    int v = tree.query(l, r);
    int res = 1 + max(dfs(l, m - 1, tree), dfs(m + 1, r, tree));
    if(v > l)
        res = max(res, dfs(l, v - 1, tree) + 1);
    if(v < r)
        res = max(res, dfs(v + 1, r, tree) + 1);
    return res;
}

int solve(int n, const vector<int> &arr)
{
    SegmentTree tree(arr);
    map<pair<int, int>, int> dp;
    int v = tree.query(0, n-1, arr);
    int res = 1;
    if(v > 0)
        res = max(res, dfs(0, v - 1, tree) + 1);
    if(v < n-1)
        res = max(res, dfs(v + 1, n-1, tree) + 1);
    return res;
}

int main() 
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    auto res = solve(n, arr);
    cout<<res<<"\n";
    return 0;
}
