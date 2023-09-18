#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

const int ms = 1e3 + 5;
string a, b;
int n, m;

int memo[ms][ms];
int dp(int i, int j) {
    if (i == n && j == m) return 0;
    if (i == n) return 0;
    if (j == m) return 0;

    if (memo[i][j] != -1) return memo[i][j];

    int ans = 0;
    if (a[i] != b[i]) {
        ans = max(dp(i + 1, j), dp(i, j + 1));
    } else {
        ans = 1 + dp(i + 1, j + 1);
    }
    return memo[i][j] = ans;
}

void solve() {
    cin >> a >> b;
    n = a.size();
    m = b.size();

    memset(memo, -1, sizeof(memo));
    cout << dp(n - 1, m - 1) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}