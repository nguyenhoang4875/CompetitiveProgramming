#include <bits/stdc++.h>
#define int long long

/**
 * https://codeforces.com/problemset/problem/1845/D
 */

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
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

const long long oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];

    vi pre(n + 1);
    For(i, 1, n) pre[i] = pre[i - 1] + a[i];

    int r = 0, mn = 0;
    int sum = 0;
    For(i, 1, n) {
        sum += a[i];
        if (mn > sum) {
            mn = sum;
            r = i;
        }
        sum = min(sum, 0LL);
    }
    if (mn >= 0) {
        cout << oo << el;
        return;
    }
    cout << pre[r] - mn << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}