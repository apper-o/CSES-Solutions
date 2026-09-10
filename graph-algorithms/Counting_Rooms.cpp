#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 1e3+3;
const int INF = 1e9+3;
const int X = 319;
 

struct pii{
    int a, b;
};


vector<pii> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;
int res=0;
char arr[MAXN][MAXN];


void mark(int a, int b)
{
    queue<pii> q;
    q.push({a, b});
    arr[b][a]='#';
    while(q.size())
    {
        auto [x, y] = q.front();
        q.pop();
        for(auto [xx, yy] : dir)
            if(arr[y+yy][x+xx]=='.')
            {
                q.push({x+xx, y+yy});
                arr[y+yy][x+xx]='#';
            }
    }
    res++;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>arr[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(arr[i][j]=='.')
                mark(j, i);
    cout<<res<<"\n";
    return 0;
}