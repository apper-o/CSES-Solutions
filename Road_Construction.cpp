#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 2*1e5+3;
const ll INF = 1e18+3;
const int X = 19;
const int R = 1<<18;
const int MOD = 1e9+7;
 
int n, m;
vector<int> p(MAXN);
vector<int> sz(MAXN, 1);
int mx = 1, res;

int get(int v){
    return (p[v]==v ? v : p[v] = get(p[v]));
}

int unite(int a, int b)
{  
    a=get(a), b=get(b);
    if(a==b)
        return 0;
    if(sz[a]<sz[b])
        swap(a, b);
    p[b]=a;
    sz[a]+=sz[b];
    mx = max(mx, sz[a]);
    return 1;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    res=n;
    for(int i=1;i<=n;i++)
        p[i]=i;
    for(int i=0,a,b;i<m;i++)
    {
        cin>>a>>b;
        res -= unite(a, b);
        cout<<res<<" "<<mx<<"\n";
    }
    return 0;
}