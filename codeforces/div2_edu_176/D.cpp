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

vvi cost(61, vi(61, oo));

void init() {
    cost[0][0] = 0;
    for (int i = 1; i < 16; i++) {
        for (int j = 60; j >= 0; j--) {
            for (int k = 60; k >= 0; k--) {
                if (j >= i) cost[j][k] = min(cost[j][k], cost[j - i][k] + (1LL << i));
                if (k >= i) cost[j][k] = min(cost[j][k], cost[j][k - i] + (1LL << i));
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = oo;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            if (n >> i == m >> j) {
                ans = min(ans, cost[i][j]);
            }
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}