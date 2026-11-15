#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Krawedz {
    int wierzcholek;
    int czas;
    int potwory;
};

struct Stan {
    int dist;
    int wierzcholek;
    int maska;

    bool operator > (const Stan &other) const {
        return dist > other.dist;
    }
};

int dijkstra(int n, int p, const vector<int> &kowale, const vector<vector<Krawedz>> &graf) {
    vector<vector<int>> dist(n + 1, vector<int>(1 << p, INF));
    priority_queue<Stan, vector<Stan>, greater<Stan>> pq;

    int start_maska = kowale[1];
    dist[1][start_maska] = 0;
    pq.push({0, 1, start_maska});

    while (!pq.empty()) {
        auto [d, v, miecze] = pq.top();
        pq.pop();

        if (d > dist[v][miecze])
            continue;

        if (v == n)
            return d;

        for (const auto &[u, czas, potwory] : graf[v]) {
            if ((miecze & potwory) == potwory) {
                int nowe_miecze = miecze | kowale[u];
                if (dist[u][nowe_miecze] > d + czas) {
                    dist[u][nowe_miecze] = d + czas;
                    pq.push({d + czas, u, nowe_miecze});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p, k;
    cin >> n >> m >> p >> k;

    vector<int> kowale(n + 1, 0);
    for (int i = 0; i < k; i++) {
        int miasto, n_potwory;
        cin >> miasto >> n_potwory;
        int maska = 0;
        for (int j = 0; j < n_potwory; j++) {
            int potwor;
            cin >> potwor;
            maska |= (1 << (potwor - 1));
        }
        kowale[miasto] |= maska;
    }

    vector<vector<Krawedz>> graf(n + 1);
    for (int i = 0; i < m; i++) {
        int v, u, czas, n_potwory;
        cin >> v >> u >> czas >> n_potwory;
        int maska = 0;
        for (int j = 0; j < n_potwory; j++) {
            int potwor;
            cin >> potwor;
            maska |= (1 << (potwor - 1));
        }
        graf[v].push_back({u, czas, maska});
        graf[u].push_back({v, czas, maska});
    }

    cout << dijkstra(n, p, kowale, graf) << "\n";
}

