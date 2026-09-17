#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9 + 3;

struct Node {
    long long sum;
    long long pref;
    long long suff;
    long long res;

    Node() : sum(0), pref(0), suff(0), res(0) {};

    Node(int val) {
        sum = val;
        int non_negative = max(val, 0);
        pref = non_negative;
        suff = non_negative;
        res = non_negative;
    }
};

struct SegmentTree {
    int n = 1;
    vector<Node> tree;

    Node merge(const Node& l, const Node& r) {
        Node res;
        res.sum = l.sum + r.sum;
        res.pref = max(l.pref, l.sum + r.pref);
        res.suff = max(l.suff + r.sum, r.suff);
        res.res = max({l.res, r.res, l.suff + r.pref});
        return res;
    }

    SegmentTree(const vector<int>& arr) {
        while (n < (int)arr.size())
            n *= 2;
        tree.resize(2 * n);

        for (int i = 0; i < (int)arr.size(); i++)
            tree[i + n] = arr[i];

        for (int i = n - 1; i > 0; i--)
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }

    long long update_and_result(int k, int val) {
        k += n - 1;
        tree[k] = Node(val);
        k /= 2;
        while (k) {
            tree[k] = merge(tree[2 * k], tree[2 * k + 1]);
            k /= 2;
        }
        return tree[1].res;
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
        int k, val;
        cin >> k >> val;
        cout << tree.update_and_result(k, val) << "\n";
    }

    return 0;
}
