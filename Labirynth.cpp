#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
//------------------------code------------------------//
const int MAXN = 1e3+3;
const int INF = 1e9+3;
const int X = 319;
 

struct pii{
    int a, b;
};


vector<pii> dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<char> let={'R', 'L', 'D', 'U'};

int n, m;
int arr[MAXN][MAXN];
queue<pii> q;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    memset(arr,-1,sizeof(arr));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char x;
            cin>>x;
            if(x=='A')
            {
                arr[i][j]=1;
                q.push({j, i});
            }
            else if(x=='B')
                arr[i][j] = INF;
            else
                arr[i][j] = (x=='.' ? 0 : -1);
        }
    pii t = {0, 0};
    while(q.size() && t.a==0)
    {
        auto [x, y] = q.front();
        q.pop();
        for(auto [xp, yp] : dir)
        {
            if(arr[y+yp][x+xp]==0)
            {
                q.push({x+xp, y+yp});
                arr[y+yp][x+xp]=arr[y][x]+1;
            }
            else if(arr[y+yp][x+xp]==INF)
            {
                t={y+yp, x+xp};
                arr[y+yp][x+xp]=arr[y][x]+1;
            }
        }
    }
    if(t.a==0)
        cout<<"NO";
    else
    {
        cout<<"YES\n";
        cout<<arr[t.a][t.b]-1<<"\n";
        string ans = "";
        for(int i=arr[t.a][t.b];i>1;i--)
        {
            for(int j=0;j<4;j++)
            {
                auto [x, y] = dir[j];
                if(arr[t.a+y][t.b+x]==arr[t.a][t.b]-1)
                {
                    t.a+=y;
                    t.b+=x;
                    ans+=let[j];
                    break;
                }
            }
        }
        for(int i=ans.size()-1;i>=0;i--)
            cout<<ans[i];
    }
    return 0;
}