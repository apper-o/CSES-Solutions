#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

string solve(int n, const vector<string> &arr)
{
    vector<pair<int, int>> cand[2];
    vector<vector<int>> vis(n, vector<int>(n));
    cand[0].push_back({0, 0});
    int tick = 0;
    string res = "";
    res += arr[0][0];
    while((int)res.size() < 2 * n - 1)
    {
        char next = 'Z';
        for(auto [y, x] : cand[tick])
        {

            if(y + 1 < n && !vis[y+1][x])
            {
                vis[y+1][x] = 1;
                if(arr[y + 1][x] < next)
                {
                    next = arr[y + 1][x];
                    cand[(tick + 1) % 2].clear();
                    cand[(tick + 1) % 2].push_back({y + 1, x});
                }
                else if(arr[y + 1][x] == next)
                    cand[(tick + 1) % 2].push_back({y + 1, x});
            }
            if(x + 1 < n && !vis[y][x+1])
            {
                vis[y][x+1] = 1;
                if(arr[y][x + 1] < next)
                {
                    next = arr[y][x + 1];
                    cand[(tick + 1) % 2].clear();
                    cand[(tick + 1) % 2].push_back({y, x + 1});
                }
                else if(arr[y][x + 1] == next)
                    cand[(tick + 1) % 2].push_back({y, x + 1});
            }
        }
        cand[tick].clear();
        res += next;
        tick = (tick + 1) % 2;
    }
    return res;
}

int main() 
{
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    auto res = solve(n, arr);
    cout<<res<<"\n";
    return 0;
}
