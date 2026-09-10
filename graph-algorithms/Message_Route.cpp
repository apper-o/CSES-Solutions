#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 1e5+3;
const int INF = 1e9+3;
const int X = 319;


int n, m;
vector<int> adj[MAXN];
vector<int> p(MAXN);

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0,a,b;i<m;i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    queue<int> q;
    q.push(1);
    p[1]=-1;
    while(q.size())
    {
        auto v = q.front();
        q.pop();
        if(v==n)
            break;
        for(int u : adj[v])
        {
            if(!p[u])
            {
                p[u]=v;
                q.push(u);
            }
        }
    }
    if(!p[n])
        cout<<"IMPOSSIBLE";
    else
    {
        int v = n;
        stack<int> s;
        while(v>0)
        {
            s.push(v);
            v=p[v];
        }
        cout<<s.size()<<"\n";
        while(s.size())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }

    return 0;
}