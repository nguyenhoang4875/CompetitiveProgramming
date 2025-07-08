#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

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

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    Rep(i, n) {
        int x;
        cin >> x;
        a[i] = (x <= k) ? 1 : -1;
    }

    auto check = [&](bool isR, vi a) {
        if (isR) reverse(all(a));
        int sum = 0;
        map<int, int> cnt;
        Rep(i, n) {
            sum += a[i];
            if (sum >= 0 and cnt.count(sum)) return true;
            cnt[sum]++;
        }
        return false;
    };
    bool ok = false;
    ok |= check(false, a);
    ok |= check(true, a);
    if (ok) {
        cout << "YES" << el;
        return;
    }

    auto getMax = [&](bool isR, vi a) {
        if (isR) reverse(all(a));
        vi preMax(n, -oo);
        preMax[0] = a[0];
        int sum = a[0];
        for (int i = 1; i < n; i++) {
            sum += a[i];
            preMax[i] = max(preMax[i - 1], sum);
        }
        if (isR) reverse(all(preMax));
        return preMax;
    };
    vi preMax = getMax(false, a);
    vi sufMax = getMax(true, a);

    for (int i = 1; i <= n - 2; i++) {
        if (preMax[i - 1] >= 0 and sufMax[i + 1] >= 0) {
            cout << "YES" << el;
            return;
        }
    }
    cout << "NO" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}