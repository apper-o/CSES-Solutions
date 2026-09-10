#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 3;

struct Edge {
    int to;
    long long cost;
};

vector<int> solve(const vector<Edge>& adj, int n) {
    vector<long long> dist(n);
    vector<int> from(n);
    vector<int> cnt(n);
    vector<int> in_queue(n);
    queue<int> q;
    int last_node = -1;

    q.push(0);
    while (!q.empty() && last_node == -1) {
        auto v = q.front();
        q.pop();
        in_queue[v] = 0;
        for (const auto& [u, cost] : adj) {
            if (dist[u] > dist[v] + cost) {
                dist[u] = dist[v] + cost;
                from[u] = v;
                if (++cnt[u] == n)
                    last_node = u;
            }
        }
    }

    if (last_node == -1)
        return vector<int>();

    for (int i = 0; i < n; i++)
        last_node = from[last_node];

    vector<int> ans;
    ans.push_back(last_node + 1);
    last_node = from[last_node];

    while (ans.front() - 1 != last_node) {
        ans.push_back(last_node + 1);
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

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
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
