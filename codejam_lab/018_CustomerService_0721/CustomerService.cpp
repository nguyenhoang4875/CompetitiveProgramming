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
    vvi a(n + 2, vi(n + 2));
    For(i, 1, n) For(j, 1, n) cin >> a[i][j];

    vvi s(n + 2, vi(n + 2));
    For(i, 1, n) {
        Rof(j, n, 0) { s[i][j] = s[i][j + 1] + a[i][j]; }
    }

    vb used(n + 1);
    int mex = 0;
    For(j, 1, n) {
        For(i, 1, n) {
            if (!used[i] and s[i][j] == n - j + 1) {
                mex++;
                used[i] = true;
                break;
            }
        }
    }
    if (mex < n) mex++;

    cout << mex << el;
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