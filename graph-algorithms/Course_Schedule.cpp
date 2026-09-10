#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 2*1e5+3;
const ll INF = 1e18+3;
const int X = 319;
const int R = 1<<18;


int n, m;
vector<int> adj[MAXN];
vector<int> in(MAXN);
vector<int> topo;

void solve()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!in[i])
            q.push(i);
    while(q.size())
    {
        int v = q.front();
        q.pop();
        topo.pb(v);
        for(int u : adj[v])
            if(!--in[u])
                q.push(u);
    }
    if(topo.size()!=n)
        cout<<"IMPOSSIBLE";
    else
        for(int v : topo)
            cout<<v<<" ";
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0,a,b;i<m;i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
        in[b]++;
    }
    solve();
    return 0;
}
