#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9 + 3;

struct SegmentTree {
    int n = 1;
    vector<int> tree;

    SegmentTree(const vector<int>& arr) {
        while (n < arr.size())
            n *= 2;
        tree.resize(2 * n, INF);

        for (int i = 0; i < arr.size(); i++)
            tree[i + n] = arr[i];

        for (int i = n - 1; i > 0; i--)
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }

    void update(int k, int val) {
        k += n - 1;
        tree[k] = val;

        while (k > 1) {
            k /= 2;
            tree[k] = min(tree[2 * k], tree[2 * k + 1]);
        }
    }

    int query(int l, int r) {
        l += n - 1, r += n - 1;
        int res = min(tree[l], tree[r]);

        while (l / 2 != r / 2) {
            if (l % 2 == 0)
                res = min(res, tree[l + 1]);
            if (r % 2 == 1)
                res = min(res, tree[r - 1]);
            l /= 2;
            r /= 2;
        }

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
    
    for(int i = 0; i < q; i++) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1)
            tree.update(a, b);
        else
            cout << tree.query(a, b) << "\n";
    }

    return 0;
}
