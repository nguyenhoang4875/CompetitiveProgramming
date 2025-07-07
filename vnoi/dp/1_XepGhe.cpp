#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Arrange Chairs: Give n white chairs, n black chair, n read chair
 * Arrange in a row with n chair without two adjency red chair
 *
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
    vi f(n + 1);  // f[i][j] number of way for first -ith chairs
    f[1] = 2;
    f[2] = 8;

    for (int i = 3; i <= n; i++) {
        f[i] = 2 * f[i - 1] + 2 * f[i - 2];
    }
    cout << f[n] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}