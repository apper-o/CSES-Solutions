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

int n, m;
vector<int> adjt[MAXN];
int dp[23][(1<<20)+3];

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0,a,b;i<m;i++)
    {
        cin>>a>>b;
        a--, b--;
        adjt[b].pb(a);
    }
    dp[0][1]=1;
    for(int mask=3;mask<(1<<n);mask++)
    {
        if(mask&(1<<(n-1)) && mask!=(1<<n)-1)
            continue;
        for(int v=0;(1<<v)<=mask;v++)
            if(mask&(1<<v))
                for(int u : adjt[v])
                    if(mask&(1<<u))
                        dp[v][mask] = (dp[v][mask] + dp[u][mask^(1<<v)]) % MOD;
    }
    cout<<dp[n-1][(1<<n)-1];
	return 0;
}