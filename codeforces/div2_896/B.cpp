#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int const oo = 1e18;
int n, k, s, e;
pair<int, int> a[200005];

int distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve() {
    cin >> n >> k >> s >> e;
    for (int i = 1; i <= n; i++) {
        int r, c;
        cin >> r >> c;
        a[i] = {r, c};
    }

    int sToM = 0;
    int eToM = 0;
    if (s <= k && e <= k) {
        cout << "0\n";
        return;
    }
    if (s > k) {
        sToM = oo;
        for (int i = 1; i <= k; i++) {
            sToM = min(sToM, distance(a[s].first, a[s].second, a[i].first,
                                      a[i].second));
        }
    }
    if (e > k) {
        eToM = oo;
        for (int i = 1; i <= k; i++) {
            eToM = min(eToM, distance(a[e].first, a[e].second, a[i].first,
                                      a[i].second));
        }
    }
    int ans = sToM + eToM;
    int distSe = distance(a[s].first, a[s].second, a[e].first, a[e].second);
    ans = min(ans, distSe);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}