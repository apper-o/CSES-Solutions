#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;


int solve(int n, const vector<int> &arr)
{
    // smallest[i] = (smallest) last number in a increasing sequence of length i
    vector<int> smallest(n);  
    smallest[0] = arr[0];
    int len = 0;
    for(int i=1;i<n;i++)
    {
        int lo = 0, hi = len + 1;
        while(lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if(smallest[mid] >= arr[i])
                hi = mid;
            else
                lo = mid + 1;
        }
        if(hi == len + 1)
            len++;
        smallest[hi] = arr[i];
    }
    return len + 1;
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
