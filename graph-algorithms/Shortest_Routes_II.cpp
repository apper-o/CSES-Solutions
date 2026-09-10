#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 500+3;
const ll INF = 1e18+3;
const int X = 319;

int n, m, q;
ll dist[MAXN][MAXN];

void solve()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for(int i=0,a,b;i<q;i++)
    {
        cin>>a>>b;
        cout<<(dist[a][b]==INF ? -1 : dist[a][b])<<"\n";
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            dist[i][j] = dist[j][i] = (i==j ? 0 : INF);
    for(ll i=0,a,b,c;i<m;i++)
    {
        cin>>a>>b>>c;
        dist[a][b]=dist[b][a]=min(dist[a][b], c);
    }  
    solve();
    return 0;
}