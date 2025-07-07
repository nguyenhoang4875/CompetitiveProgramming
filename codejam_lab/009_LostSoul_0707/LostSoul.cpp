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
    int n;
    cin >> n;
    vi a(n + 1);
    vi b(n + 1);
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];

    if (a[n] == b[n]) {
        cout << n << el;
        return;
    }
    vb seen(n + 1, false);  // seen for case: a[i] == a[i + 2], a[i] == b[i + 2] and reverse
    int ans = 0;
    Rof(i, n - 1, 1) {
        if (a[i] == b[i] or a[i] == a[i + 1] or b[i] == b[i + 1] or seen[a[i]] or seen[b[i]]) {
            ans = i;
            break;
        }
        seen[a[i + 1]] = seen[b[i + 1]] = true;
    }
    cout << ans << el;
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