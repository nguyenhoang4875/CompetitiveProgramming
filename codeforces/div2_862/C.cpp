#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> lines(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i];
    }
    sort(lines.begin(), lines.end());

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int ind = lower_bound(lines.begin(), lines.end(), b) - lines.begin();
        if (ind < n && (lines[ind] - b) * (lines[ind] - b) < 4 * a * c) {
            cout << "YES\n" << lines[ind] << "\n";
            continue;
        }
        if (ind > 0 && (lines[ind - 1] - b) * (lines[ind - 1] - b) < 4 * a * c) {
            cout << "YES\n" << lines[ind - 1] << "\n";
            continue;
        }
        cout << "NO\n";
    }
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}