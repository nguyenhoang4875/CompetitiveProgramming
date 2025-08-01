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
int n, m;

void solve() {
    cin >> n >> m;
    vi a(n);
    for (auto& x : a) cin >> x;
    vi b(m);
    for (auto& x : b) cin >> x;

    if (n == 1) {
        cout << "YES" << el;
        return;
    }
    sort(all(b));
    int bb = b[m - 1];
    a[n - 1] = max(a[n - 1], bb - a[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        int tmp = -oo;
        if (a[i] <= a[i + 1]) tmp = a[i];
        auto up = upper_bound(all(b), a[i] + a[i + 1]);
        if (up != b.begin()) {
            up--;
            tmp = max(tmp, *up - a[i]);
        }
        if (tmp == -oo) {
            cout << "NO" << el;
            return;
        }
        a[i] = tmp;
    }
    cout << "YES" << el;
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