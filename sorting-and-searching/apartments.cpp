#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> preference(n);
    vector<int> apartment(m);

    for (int i = 0; i < n; i++)
        cin >> preference[i];
    for (int i = 0; i < m; i++)
        cin >> apartment[i];

    sort(preference.begin(), preference.end());
    sort(apartment.begin(), apartment.end());

    int i = 0, j = 0, res = 0;
    while (i < n && j < m) {
        if (preference[i] + k < apartment[j])
            i++;
        else if (preference[i] - k > apartment[j])
            j++;
        else {
            i++;
            j++;
            res++;
        }
    }

    cout << res << "\n";
    return 0;
}