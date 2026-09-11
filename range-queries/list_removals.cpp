#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9 + 3;

struct SegmentTree {
    int n = 1;
    vector<int> tree;

    SegmentTree(int size) {
        while (n < size)
            n *= 2;
        tree.resize(2 * n);

        for (int i = 0; i < size; i++)
            tree[i + n] = 1;

        for (int i = n - 1; i > 0; i--)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    int find_remove(int pos) {
        int node = 1;

        while (node < n) {
            tree[node]--;

            if (tree[2 * node] < pos) {
                pos -= tree[2 * node];
                node = 2 * node + 1;
            } else
                node *= 2;
        }

        tree[node] = 0;
        return node - n;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree tree(n);

    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        int orginal_idx = tree.find_remove(pos);
        cout << arr[orginal_idx] << " ";
    }

    return 0;
}
