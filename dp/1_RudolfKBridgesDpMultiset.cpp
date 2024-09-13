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
int n, m, k, d;

void solve() {
    cin >> n >> m >> k >> d;
    vvi a(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // f[i][j] is minimum cost to build a bridges on row i and end at j
    vi ret(n);
    for (int i = 0; i < n; i++) {
        vi f(m, oo);
        f[0] = 1;
        multiset<int> mst = {1};
        for (int j = 1; j < m - 1; j++) {
            f[j] = *mst.begin() + a[i][j] + 1;
            if (j - d - 1 >= 0) {
                mst.erase(mst.find(f[j - d - 1]));
            }
            mst.insert(f[j]);
        }
        f[m - 1] = 1 + *mst.begin();
        ret[i] = f[m - 1];
    }

    // two pointers for k consecutive bridges
    int ans = oo;
    int l = 0;
    int sum = 0;
    for (int r = 0; r < n; r++) {
        sum += ret[r];
        if (r - l + 1 == k) {
            ans = min(ans, sum);
            sum -= ret[l];
            l++;
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