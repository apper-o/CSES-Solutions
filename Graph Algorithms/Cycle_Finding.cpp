#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 2*1e5+3;
const ll INF = 1e18+3;
const int X = 319;
const int R = 1<<15;


int n, m;
vector<pair<int, ll>> adj[MAXN];
vector<ll> dist(MAXN, INF);
vector<int> cnt(MAXN);
vector<int> p(MAXN);
vector<int> on(MAXN);

void solve(int a)
{
    queue<int> q;
    q.push(a);
    dist[a]=0;
    while(q.size())
    {
        int v = q.front();
        q.pop();
        on[v] = 0;
        if(cnt[v]++>n)
        {
            for(int i=0;i<=n;i++)
                v=p[v];
            stack<int> s;
            s.push(v);
            int u = v;
            while(p[v]!=u)
            {
                v = p[v];
                s.push(v);
            }
            cout<<"YES\n";
            cout<<u<<" ";
            while(s.size())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
            exit(0);
        }
        for(auto [u, w] : adj[v])
        {
            if(dist[u]>dist[v]+w)
            {
                dist[u] = dist[v]+w;
                p[u] = v;
                if(!on[u])
                {
                    on[u]=1;
                    q.push(u);
                }
            }
        }
    }
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
    for(int i=1;i<=n;i++)
        if(dist[i]==INF)
            solve(i);
    cout<<"NO\n";
    return 0;
}