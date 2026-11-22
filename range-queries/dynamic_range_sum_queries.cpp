#include <bits/stdc++.h>
using namespace std;

long long query(int a, int b, const vector<long long> &tree) {
    long long res = tree[a];
    if (a == b) 
        return res;
    res += tree[b];
    
    while (a / 2 != b / 2) {
        if (a % 2 == 0) 
            res += tree[a + 1];
        if (b % 2 == 1)
            res += tree[b - 1];
        a /= 2;
        b /= 2;
    }
    
    return res;
}

void update(int k, int val, vector<long long> &tree) {
    tree[k] = val;
    
    while (k > 1) {
        k /= 2;
        tree[k] = tree[2 * k] + tree[2 * k + 1]; 
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q; 
    
    int R = 1;
    while (R < n) 
        R *= 2;
    vector<long long> tree(2 * R); 
    
    for (int i = 0; i < n; i++)
        cin >> tree[i + R]; 
    
    for (int i = R - 1; i > 0; i--)
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    
    for (int i = 0; i < q; i++) {
        int t, a, b;
        cin >> t >> a >> b; 
        if (t == 1) {
            update(a + R - 1, b, tree);
        } else {
            cout << query(a + R - 1, b + R - 1, tree) << "\n";
        }
    }
    
    return 0;
}
