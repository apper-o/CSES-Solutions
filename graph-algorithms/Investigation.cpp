#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 2*1e5+3;
const ll INF = 1e18+3;
const int X = 319;
const int R = 1<<18;
const int MOD = 1e9+7;

struct pii{
    ll a, b;
};

int n, m;
vector<pii> adj[MAXN];
vector<ll> dist(MAXN, INF);
vector<ll> mn(MAXN, INF);
vector<int> mx(MAXN);
vector<int> cnt(MAXN);

void solve()
{
    dist[1]=0;
    mn[1]=0;
    cnt[1]=1;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});
    while(pq.size())
    {
        auto [c, v] = pq.top();
        c=-c;
        pq.pop();
        if(dist[v] != c)
            continue;
        for(auto [u, w] : adj[v])
        {
            if(dist[u] > c + w)
            {
                dist[u] = c+w;
                mn[u] = mn[v]+1;
                mx[u] = mx[v]+1;
                cnt[u] = cnt[v];
                pq.push({-c-w, u});
            }
            else if(dist[u]==c+w)
            {
                mn[u] = min(mn[u], mn[v]+1);
                mx[u] = max(mx[u], mx[v]+1);
                cnt[u] = (cnt[u] + cnt[v]) % MOD;
            }
        }
    }
    cout<<dist[n]<<" "<<cnt[n]<<" "<<mn[n]<<" "<<mx[n]<<"\n";
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