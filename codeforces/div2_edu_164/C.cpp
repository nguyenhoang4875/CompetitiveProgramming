#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
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
int n;
string x, y;

void solve() {
    cin >> x >> y;
    n = sz(x);
    bool firstDiff = false;
    if (y > x) swap(x, y);
    for (int i = 0; i < n; i++) {
        if (x[i] == y[i]) continue;
        if (!firstDiff) {
            firstDiff = true;
            continue;
        }
        if (x[i] > y[i]) swap(x[i], y[i]);
    }
    cout << x << el;
    cout << y << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}