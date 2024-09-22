#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

void solve() {
    cin >> n;
    vi a(n);

    for (auto& e : a) cin >> e;

    if (n <= 2) {
        cout << -1 << el;
        return;
    }

    int sum = 0, maxVal = 0;
    for (auto& e : a) {
        sum += e;
        maxVal = max(maxVal, e);
    }

    auto check = [&](int val) {
        int cnt = 0;
        bool firstMaxVal = false;
        for (auto e : a) {
            if (!firstMaxVal and e == maxVal) {
                firstMaxVal = true;
                continue;
            }
            if (sum + val > 2 * e * n) cnt++;
        }
        return cnt >= (n / 2 + 1);
    };

    int l = 0, r = oo;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}