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

const long long oo = 2e9, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, h;

struct cow {
    int h, w, s;
};

void solve() {
    cin >> n >> h;
    vector<cow> a(n);
    for (auto& x : a) cin >> x.h >> x.w >> x.s;
    int maxMask = (1LL << n) - 1;
    vi f(maxMask + 1, -oo);
    // f[mask]: maximum length at set mask
    for (int i = 0; i < n; i++) {
        f[1 << i] = a[i].s;
    }

    for (int mask = 0; mask <= maxMask; mask++) {
        for (int i = 0; i < n; i++) {
            if (!getBit(mask, i)) {
                int newMask = setBit(mask, i);
                if (f[mask] < a[i].w) continue;
                f[newMask] = max(f[newMask], min(f[mask] - a[i].w, a[i].s));
            }
        }
    }

    int ret = -oo;
    for (int mask = 0; mask <= maxMask; mask++) {
        int totH = 0;
        for (int i = 0; i < n; i++) {
            if (getBit(mask, i)) totH += a[i].h;
            if (totH >= h) break;
        }
        if (totH >= h) {
            if (f[mask] != -oo) ret = max(ret, f[mask]);
        }
    }
    if (ret >= 0)
        cout << ret << el;
    else
        cout << "Mark is too tall" << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);

    int tcs = 1;
    // cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}