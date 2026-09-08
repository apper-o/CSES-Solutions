#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 3;

struct Edge {
    int to;
    long long cost;
};

vector<int> solve(const vector<vector<Edge>>& adj, int n) {
    vector<long long> dist(n + 1);
    vector<int> from(n + 1);
    vector<int> len(n + 1);
    vector<bool> in_queue(n + 1, 1);
    queue<int> q;
    int last_node = 0;

    for (int i = 1; i <= n; i++)
        q.push(i);

    while (!q.empty() && !last_node) {
        auto v = q.front();
        q.pop();
        in_queue[v] = 0;
        for (const auto& [u, cost] : adj[v]) {
            if (dist[u] > dist[v] + cost) {
                dist[u] = dist[v] + cost;
                from[u] = v;
                len[u] = len[v] + 1;
                if (len[u] == n) {
                    last_node = u;
                    break;
                }
                if (!in_queue[u]) {
                    q.push(u);
                    in_queue[u] = 1;
                }
            }
        }
    }

    if (!last_node)
        return vector<int>();

    for (int i = 0; i < n; i++)
        last_node = from[last_node];

    vector<int> ans;
    ans.push_back(last_node);
    last_node = from[last_node];

    while (ans.front() != last_node) {
        ans.push_back(last_node);
        last_node = from[last_node];
    }
    ans.push_back(ans.front());

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<int> ans = solve(adj, n);

    if (ans.empty())
        cout << "NO";
    else {
        cout << "YES\n";
        for (const auto& v : ans)
            cout << v << " ";
    }

    return 0;
}
