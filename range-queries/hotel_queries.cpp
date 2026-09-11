#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9 + 3;

struct SegmentTree {
    int n = 1;
    vector<int> tree;

    SegmentTree(const vector<int>& arr) {
        while (n < (int)arr.size())
            n *= 2;
        tree.resize(2 * n);

        for (int i = 0; i < (int)arr.size(); i++)
            tree[i + n] = arr[i];

        for (int i = n - 1; i > 0; i--)
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    int find(int ammount) {
        if (tree[1] < ammount)
            return 0;
        else
            return find_update(1, ammount);
    }

    int find_update(int node, int ammount) {
        if (node >= n) {
            tree[node] -= ammount;
            return node - n + 1;
        }

        int res = find_update(2 * node + (tree[2 * node] < ammount), ammount);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree tree(arr);

    for (int i = 0; i < q; i++) {
        int ammount;
        cin >> ammount;
        cout << tree.find(ammount) << " ";
    }

    return 0;
}
