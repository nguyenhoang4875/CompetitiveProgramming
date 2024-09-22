#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

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
int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, x;
int a[ms], b[ms], c[ms];

void solve() {
    cin >> n >> x;

    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];
    For(i, 1, n) cin >> c[i];

    if (x == 0) {
        cout << "Yes" << el;
        return;
    }

    auto check = [&](int val) {
        bool ok = true;
        for (int i = 30; i >= 0; i--) {
            if (!getBit(val, i)) continue;
            if (!getBit(x, i)) {
                ok = false;
                break;
            }
        }

        return ok;
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (check(a[i])) {
            ans |= a[i];
        } else {
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (check(b[i])) {
            ans |= b[i];
        } else {
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (check(c[i])) {
            ans |= c[i];
        } else {
            break;
        }
    }
    if (ans == x) {
        cout << "Yes" << el;
    } else
        cout << "No" << el;
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