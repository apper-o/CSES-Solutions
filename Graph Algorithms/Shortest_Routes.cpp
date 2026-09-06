#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long cost;
};

void dijkstra(int start, const vector<vector<Edge>>& adj, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d > dist[v])
            continue;

        for (const auto& edge : adj[v]) {
            if (dist[edge.to] > d + edge.cost) {
                dist[edge.to] = d + edge.cost;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
    }

    vector<long long> dist(n, INF);
    dijkstra(0, adj, dist);

    for (int i = 0; i < n; i++) {
        cout << dist[i] << (i + 1 == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}