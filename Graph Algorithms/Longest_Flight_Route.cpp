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
vector<int> ts;
vector<int> dp(MAXN);
vector<int> p(MAXN);
vector<int> ok(MAXN);

void solve()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!in[i])
            q.push(i);
    while(q.size())
    {
        auto v = q.front();
        q.pop();
        ts.pb(v);
        for(auto u : adj[v])
            if(!--in[u])
                q.push(u);
    }
    ok[1]=1;
    for(int v : ts)
    {
        if(!ok[v])
            continue;
        dp[v]=max(dp[v], 1);
        for(int u : adj[v])
        {
            ok[u]=1;
            if(dp[u] < dp[v]+1)
            {
                dp[u]=dp[v]+1;
                p[u]=v;
            }
        }
    }
    if(!ok[n])
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    vector<int> ans;
    int v = n;
    while(v)
    {
        ans.pb(v);
        v=p[v];
    }
    cout<<ans.size()<<"\n";
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0,a,b;i<m;i++)
    {
        cin>>a>>b;
        if(b==1)
            continue;
        adj[a].pb(b);
        in[b]++;
    }
    solve();
    return 0;
}
