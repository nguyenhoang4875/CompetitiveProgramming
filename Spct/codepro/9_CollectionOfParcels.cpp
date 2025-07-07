#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    pair<int, int> a, b;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    vector<pair<int, int>> p(n);  // parcels
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    auto getDistance = [](pair<int, int> p1, pair<int, int> p2) {
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    };

    auto cal = [&](int cnt) {
        int sumA = 0;
        int sumB = 0;
        if (cnt > 0) {
            int numPac = 1;
            sumA = getDistance(a, p[0]);
            for (int i = 0; i < cnt - 1; i++) {
                sumA += (1 + numPac) * getDistance(p[i], p[i + 1]);
                numPac++;
            }
            sumA += (1 + numPac) * getDistance(a, p[cnt - 1]);
        }
        if (cnt < n) {
            int numPac = 1;
            sumB = getDistance(b, p[cnt]);
            for (int i = cnt; i < n - 1; i++) {
                sumB += (1 + numPac) * getDistance(p[i], p[i + 1]);
                numPac++;
            }
            sumB += (1 + numPac) * getDistance(b, p[n - 1]);
        }
        return sumA + sumB;
    };

    int ans = 1e9;
    sort(p.begin(), p.end());
    do {
        for (int cnt = 0; cnt <= n; cnt++) {
            ans = min(ans, cal(cnt));
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}