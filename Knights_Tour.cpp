#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 2*1e5+3;
const ll INF = 1e9+3;
const int X = 319;
const int R = 1<<18;
const int MOD = 1e9+7;

struct pii{
    int x, y, s;
};

int arr[10][10];
vector<pair<int, int>> dir = {{1, 2}, {1, -2}, {-1, -2}, {-1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}}; 

bool ok(int y, int x)
{
    return (min(x, y) > 0 && max(x, y) < 9 && !arr[y][x]);
}

int check(int y, int x)
{
    int res = 0;
    for(auto [dx, dy] : dir)
        res += ok(y + dy, x + dx);
    return res;
}

bool solve(int x, int y, int step)
{   
    arr[y][x] = step;
    if(step==64)
        return true; 
    vector<pii> tmp;
    for(auto [dx, dy] : dir)
    {
        int xp = dx + x, yp = dy + y;
        if(!ok(yp, xp))
            continue;
        tmp.pb({xp, yp, check(yp, xp)});
    }
    sort(tmp.begin(), tmp.end(), [] (pii a, pii b){
        return a.s < b.s;
    });
    for(auto [a, b, s] : tmp)
        if(solve(a, b, step+1))
            return true;
    arr[y][x]=0;
    return false;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int x, y;
    cin>>x>>y;
    solve(x, y, 1);

    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";    
    }

    return 0;
}