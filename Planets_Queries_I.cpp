#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 2*1e5+3;
const ll INF = 1e18+3;
const int X = 30;
const int R = 1<<18;
const int MOD = 1e9+7;

int n, q;
int anc[MAXN][X];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        anc[i][0] = x;
    }
    for(int x=1;x<X;x++)
        for(int i=1;i<=n;i++)
            anc[i][x] = anc[anc[i][x-1]][x-1];
    for(int i=0,v,k;i<q;i++)
    {
        cin>>v>>k;
        for(int x=X-1;x>=0;x--)
            if((1ll<<x) <= k)
            {
                v = anc[v][x];
                k-=(1ll<<x);
            }
        cout<<v<<"\n";
    }
    return 0;
}