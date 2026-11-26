#include <bits/stdc++.h>
using namespace std;

void toposort(const vector<vector<int>> &adj, vector<int> &indeg, vector<int> &res, int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if(indeg[i] == 0)
            q.push(i);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        res.push_back(v);
        
        for (int u : adj[v])
            if (--indeg[u] == 0)
                q.push(u);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    
    vector<int> res; 
    toposort(adj, indeg, res, n);
    
    if (res.size() < n) {
        cout << "IMPOSSIBLE"; 
    } else {
        for(int v : res)
            cout << v << " ";
    }
    
    return 0;
}

