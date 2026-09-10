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

int n;
vector<int> adj[MAXN];
vector<int> vis(MAXN);
string ans="";

void dfs(int v)
{
    while(adj[v].size())
    {
        int u = adj[v].back();
        adj[v].pop_back();
        dfs(u);
    }
    ans+=char('0'+(v&1));
}

void solve()
{
    cin>>n;
    if(n==1)
    {
        cout<<"01\n";
        return;
    }
    for(int m=0;m<(1<<(n-1));m++)
    {
        int a = (m<<1) % (1<<(n-1));
        adj[m].pb(a);
        adj[m].pb(a+1);
    }
    dfs(0);
    for(int i=0;i<n-2;i++)
        ans+='0';
    cout<<ans<<"\n";
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}