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

bool solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    Rep(i, n) cin >> a[i];
    if (k <= 2) {
        return true;
    }

    vi a1 = a;

    sort(all(a1));
    int x = a1[k - 2];
    vi b;
    b.reserve(n);
    Rep(i, n) {
        if (a[i] <= x) b.pb(a[i]);
    }

    int m = b.size();
    int l = 0, r = m - 1;
    int cnt = 0;
    while (l < r) {
        if (b[l] == b[r]) {
            l++, r--;
        } else {
            if (max(b[l], b[r]) < x) {
                return false;
            }
            if (b[l] == x) {
                l++;
            } else r--;
            cnt++;
        }
    }
    return m - cnt >= k - 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        if (solve()) cout << "YES" << el;
        else cout << "NO" << el;
    }
    return 0;
}