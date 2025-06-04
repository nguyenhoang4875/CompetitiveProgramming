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
const int ms = 2e5 + 5;
int n, k;
int ans[ms];

int f(int n) { return n * n / 2; }

void cal(int l, int r, int k) {
    // base case
    if (l > r) return;

    if (k <= f(r - l)) {
        ans[l] = l;
        cal(l + 1, r, k);
    } else {
        ans[l] = r;
        ans[r] = l;
        int val = 2 * (r - l);
        cal(l + 1, r - 1, k - val);
    }
}

void solve() {
    cin >> n >> k;
    int kMax = 0;
    kMax = f(n);
    if (k & 1 or k > kMax) {
        cout << "No" << el;
        return;
    }
    cout << "Yes" << el;
    cal(1, n, k);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << el;
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