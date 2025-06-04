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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int mn1 = min(a, b), mx1 = max(a, b);
    int mn2 = min(c, d), mx2 = max(c, d);

    vi up, low;
    for (int i = mn1 + 1; i < mx1; i++) {
        low.pb(i);
    }

    for (int i = 1; i <= 12; i++) {
        bool diff = true;
        for (auto e : low) {
            if (e == i) {
                diff = false;
                break;
            }
        }
        if (diff) up.pb(i);
    }
    int hasUp = false, hasLow = false;
    for (auto e : up) {
        if (c == e or d == e) {
            hasUp = true;
            break;
        }
    }
    for (auto e : low) {
        if (c == e or d == e) {
            hasLow = true;
            break;
        }
    }
    if (hasUp and hasLow) {
        cout << "YES" << el;
    } else {
        cout << "NO" << el;
    }
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