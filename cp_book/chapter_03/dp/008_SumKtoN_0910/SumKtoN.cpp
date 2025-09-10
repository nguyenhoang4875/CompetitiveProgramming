#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
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

const long long oo = 2e18, mod = 1e6;
const int ms = 2e5 + 5;

void solve() {
    // Bottom up
    vvi f1(110, vi(110));

    for (int i = 0; i <= 100; i++) f1[i][1] = 1;

    for (int j = 1; j < 100; j++) {
        for (int i = 0; i <= 100; i++) {
            for (int split = 0; split <= 100 - i; split++) {
                f1[i + split][j + 1] += f1[i][j];
                f1[i + split][j + 1] %= mod;
            }
        }
    }

    while (true) {
        int n, k;
        cin >> n >> k;
        if (!n and !k) return;

        vvi memo(k + 1, vi(n + 1, -1));

        function<int(int, int)> f = [&](int n, int k) {
            if (k == 1) return 1;
            int &ans = memo[k][n];
            if (ans != -1) return ans;

            ans = 0;
            for (int u = 0; u <= n; u++) {
                ans = (ans + f(n - u, k - 1)) % mod;
            }
            return ans;
        };

        // cout << f(n, k) << el;
        cout << f1[n][k] << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}