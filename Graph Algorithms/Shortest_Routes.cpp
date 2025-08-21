#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 1e5+3;
const ll INF = 1e18+3;
const int X = 319;
 
struct pii{
    int a; ll b;
};
 
int n, m;
vector<pii> adj[MAXN];
vector<ll> dist(MAXN, INF);
 
struct cmp{ // a is above b if operator() = false
    bool operator() (pii a, pii b){
        return a.b > b.b;
    }
};
 
priority_queue<pii, vector<pii>, cmp> pq;
 
void solve()
{
    pq.push({1, 0});
    dist[1]=0;
    while(pq.size())
    {
        auto [v, c] = pq.top();
        pq.pop();
        if(c>dist[v])  
            continue;
        for(auto [u, w] : adj[v])
        {
            if(dist[u] > c + w)
            {   
                dist[u] = c + w;
                pq.push({u, c+w});
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
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
