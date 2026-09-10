#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 2*1e5+3;
const ll INF = 1e18+3;
const int X = 319;
 
struct pii{
    int a, b;
};
 
struct tpl{
    int v;
    ll c;
    int s;
};
 
struct cmp{
    bool operator () (tpl a, tpl b){
        return (a.c==b.c ? a.s>b.s : a.c>b.c); 
    }
};
 
 
int n, m;
vector<pii> adj[MAXN];
ll dist[MAXN][2];
 
void solve()
{
    memset(dist,0x3f,sizeof(dist));
    dist[1][0] = dist[1][1] = 1;
    priority_queue<tpl, vector<tpl>, cmp> q;
    q.push({1, 0, 1});
    while(q.size())
    {
        auto [v, c, s] = q.top();
        q.pop();
        if(dist[v][s]<c)
            continue;
        for(auto [u, w] : adj[v])
        {   
            if(dist[u][s]>c+w)
            {
                dist[u][s] = c+w;
                q.push({u, c+w, s});
            }
            if(s && dist[u][0]>c+w/2)
            {
                dist[u][0] = c+w/2;
                q.push({u, c+w/2, 0});
            }
        }
    }
    cout<<dist[n][0]<<"\n";
}
 
int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0,a,b,c;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].pb({b, c});
    }
    solve();
    return 0;
}