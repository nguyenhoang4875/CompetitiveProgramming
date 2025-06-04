#include <bits/stdc++.h>
#define int long long

using namespace std;

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
    vi a(n);
    for (auto &x : a) cin >> x;

    int mx = n, mn = 1;
    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l] == mn) {
            mn++;
            l++;
            continue;
        }
        if (a[l] == mx) {
            mx--;
            l++;
            continue;
        }
        if (a[r] == mn) {
            mn++;
            r--;
            continue;
        }
        if (a[r] == mx) {
            mx--;
            r--;
            continue;
        }
        cout << l + 1 << " " << r + 1 << el;
        return;
    }
    cout << -1 << el;
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