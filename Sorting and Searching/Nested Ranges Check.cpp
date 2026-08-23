#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

struct pii {
    int a, b;
};

struct tpl {
    int a, b, id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<tpl> points(n);
    vector<int> contains(n);
    vector<int> is_contained(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].a >> points[i].b;
        points[i].id = i;
    }

    // A range x2, y2 is contained by another range x1, y1 if x1 <= x2 and y2 <= y1.
    // First condition can be eliminated by sorting by x.
    sort(points.begin(), points.end(), [](const tpl& a, const tpl& b) {
        return (a.a == b.a ? a.b > b.b : a.a < b.a);
    });

    int max_b = 0;
    for (int i = 0; i < n; i++) {
        is_contained[points[i].id] = (max_b >= points[i].b);
        max_b = max(max_b, points[i].b);
    }

    // Similarly, we check if a range contains another range
    int min_b = INF;
    for (int i = n - 1; i >= 0; i--) {
        contains[points[i].id] = (min_b <= points[i].b);
        min_b = min(min_b, points[i].b);
    }

    for(int i=0;i<n;i++)
        cout << contains[i] << " ";
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout << is_contained[i] << " ";

    return 0;
}
