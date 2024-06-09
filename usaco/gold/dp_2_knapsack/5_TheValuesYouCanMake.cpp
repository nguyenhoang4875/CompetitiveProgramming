#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 500 + 5;
int n, k;
int c[ms];
bool dp[ms][ms];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    // dp[i][j]: i value subset can get, j: sum can get from the set has value i
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int price = k; price >= 0; price--) {
            if (price - c[i] < 0) continue;

            for (int sum = price - c[i]; sum >= 0; sum--) {
                if (dp[price - c[i]][sum]) {
                    dp[price][sum] = true;  // not include c[i]
                    dp[price][sum + c[i]] = true;
                }
            }
        }
    }

    vi ans;
    for (int sum = 0; sum <= k; sum++) {
        if (dp[k][sum]) {
            ans.push_back(sum);
        }
    }
    cout << ans.size() << el;
    for (auto e : ans) cout << e << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}