#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 1e5+3;
const ll INF = 1e18+3;
const int X = 319;
const int R = 1<<15;

int n, m, k;
vector<pair<ll, ll>> adj[MAXN];
priority_queue<ll> dist[MAXN];

void solve()
{
    priority_queue<pair<ll, ll>> pq;
    dist[1].push(0);
    pq.push({0, 1});
    while(pq.size())
    {
        auto [c, v] = pq.top();
        c=-c;
        pq.pop();
        if(c > dist[v].top())
            continue;
        for(auto [u, w] : adj[v])
        {
            if(dist[u].size()==k)
            {
                if(dist[u].top() <= c+w)
                    continue;
                dist[u].pop();
            }
            dist[u].push(c+w);
            pq.push({-(c+w), u});
        }
    }
    vector<ll> ans;
    while(dist[n].size())
    {
        ans.pb(dist[n].top());
        dist[n].pop();
    }
    reverse(ans.begin(), ans.end());
    for(ll i : ans)
        cout<<i<<" ";
}
 
int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=0,a,b,c;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].pb({b, c});
    }
    solve();
    return 0;
}