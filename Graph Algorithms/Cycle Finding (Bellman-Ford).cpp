#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 3;

struct Edge {
    int from;
    int to;
    long long cost;
};

vector<int> solve(const vector<Edge>& edges, int n) {
    vector<long long> dist(n);
    vector<int> from(n);
    int last_node = -1;

    for (int i = 0; i < n; i++) {
        for (const auto& [v, u, cost] : edges) {
            if (dist[u] > dist[v] + cost) {
                dist[u] = dist[v] + cost;
                from[u] = v;
                if (i == n - 1)
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
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
        edges[i].from--, edges[i].to--;
    }

    vector<int> ans = solve(edges, n);

    if (ans.empty())
        cout << "NO";
    else {
        cout << "YES\n";
        for (const auto& v : ans)
            cout << v << " ";
    }

    return 0;
}
