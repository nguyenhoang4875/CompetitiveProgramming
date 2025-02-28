#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://vjudge.net/problem/CodeForces-1519D
 */

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

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
int n;

void solve() {
    cin >> n;
    vi a(n + 1), b(n + 1);
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];

    vi pre(n + 2);
    For(i, 1, n) { pre[i] = pre[i - 1] + a[i] * b[i]; }

    int ans = pre[n];
    For(c, 1, n) {
        int sum = a[c] * b[c];
        for (int l = c - 1, r = c + 1; l >= 1 and r <= n; l--, r++) {
            sum += a[l] * b[r] + a[r] * b[l];
            sum += pre[l - 1] + pre[n] - pre[r];
            ans = max(ans, sum);
            sum -= pre[l - 1] + pre[n] - pre[r];
        }
        sum = 0;
        for (int l = c, r = c + 1; l >= 1 and r <= n; l--, r++) {
            sum += a[l] * b[r] + a[r] * b[l];
            sum += pre[l - 1] + pre[n] - pre[r];
            ans = max(ans, sum);
            sum -= pre[l - 1] + pre[n] - pre[r];
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}