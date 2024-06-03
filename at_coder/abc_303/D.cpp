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
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int x, y, z;
string s;

void solve() {
    cin >> x >> y >> z;
    cin >> s;
    int n = s.size();

    vvi dp(n + 1, vi(2, oo));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        if (s[i] == 'A') cur = 1;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                int val = dp[i][j];
                if (j != k) val += z;
                if (cur == k)
                    val += x;
                else
                    val += y;
                dp[i + 1][k] = min(dp[i + 1][k], val);
            }
        }
    }
    int ans = min(dp[n][0], dp[n][1]);
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}