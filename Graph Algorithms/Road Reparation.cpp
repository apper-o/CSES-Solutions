#include <bits/stdc++.h>
using namespace std;

const long long INF = 2e18 + 3;

struct Edge {
    int from;
    int to;
    long long cost;
};

struct DSU {
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int get(int v) {
        return parent[v] == v ? v : parent[v] = get(parent[v]);
    }

    bool unite(int v, int u) {
        v = get(v), u = get(u);
        if (v != u) {
            if (size[v] < size[u])
                swap(v, u);
            size[v] += size[u];
            parent[u] = v;
            return true;
        }
        return false;
    }
};

long long solve(vector<Edge>& edges, int n) {
    DSU dsu(n);

    sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
        return a.cost < b.cost;
    });

    long long res = 0;
    int edges_count = 0;
    for (const auto& [v, u, cost] : edges) {
        if (dsu.unite(v, u)) {
            res += cost;
            edges_count++;
            if (edges_count == n - 1)
                break;
        }
    }

    return (edges_count == n - 1 ? res : -1);
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
        edges[i] = {a, b, c};
    }

    auto res = solve(edges, n);
    if (res == -1)
        cout << "IMPOSSIBLE\n";
    else
        cout << res << "\n";

    return 0;
}
