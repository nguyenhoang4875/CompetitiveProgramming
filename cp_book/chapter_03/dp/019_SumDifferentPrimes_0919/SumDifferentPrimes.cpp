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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

vector<int> prime;
void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) is_prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (is_prime[p]) prime.push_back(p);
}

void solve() {
    sieve(1200);

    while (true) {
        int n, k;
        cin >> n >> k;
        if (!n and !k) return;

        vi p;
        for (auto& e : prime) {
            if (e <= n) p.pb(e);
            else break;
        }

        int m = p.size();
        if (m < k) {
            cout << 0 << el;
            continue;
        }

        // top down
        vector<vvi> memo(k + 1, vvi(m + 1, vi(n + 1, -1)));
        function<int(int, int, int)> f = [&](int k, int idx, int n) {
            if (k == 0) {
                if (n == 0) return 1;
                return 0;
            }
            if (idx < 0) return 0;
            int& ans = memo[k][idx][n];
            if (ans != -1) return ans;

            int v1 = f(k, idx - 1, n);
            int v2 = 0;
            if (n >= p[idx]) v2 = f(k - 1, idx - 1, n - p[idx]);
            ans = v1 + v2;
            return ans;
        };

        cout << f(k, m - 1, n) << el;

        // // Bottom up
        // vector<vvi> dp(k + 1, vvi(m + 1, vi(n + 1, 0)));

        // // Base case: dp[0][i][0] = 1 for all i
        // for (int i = 0; i <= m; i++) {
        //     dp[0][i][0] = 1;
        // }

        // // Fill the DP table bottom-up
        // for (int curr_k = 1; curr_k <= k; curr_k++) {
        //     for (int idx = 1; idx <= m; idx++) {
        //         for (int curr_n = 0; curr_n <= n; curr_n++) {
        //             // Don't take current prime
        //             dp[curr_k][idx][curr_n] = dp[curr_k][idx - 1][curr_n];

        //             // Take current prime if possible
        //             if (curr_n >= p[idx - 1]) {
        //                 dp[curr_k][idx][curr_n] += dp[curr_k - 1][idx - 1][curr_n - p[idx - 1]];
        //             }
        //         }
        //     }
        // }

        // cout << dp[k][m][n] << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}