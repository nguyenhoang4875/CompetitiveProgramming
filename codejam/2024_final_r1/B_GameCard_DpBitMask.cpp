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
int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m;

void solve() {
    cin >> n >> m;
    vi a(n);
    for (auto& x : a) cin >> x;
    vb used(2 * n + 1, false);
    for (int i = 0; i < n; i++) {
        used[a[i] + n] = true;
    }
    used[n] = true;
    vi b;
    for (int i = 0; i <= 2 * n; i++) {
        if (!used[i]) {
            b.pb(i - n);
        }
    }

    int maxMask = (1LL << n) - 1;
    vvi f(maxMask + 1, vi(n + 1, 0));
    // f[mask][score] : number way to get at mask have score is score
    f[0][0] = 1;  // base case

    for (int mask = 0; mask <= maxMask; mask++) {
        int cnt = __builtin_popcount(mask);
        if (cnt >= n) continue;  // number position of is set for Albert

        for (int i = 0; i < n; i++) {
            if (!getBit(mask, i)) {
                int newMask = setBit(mask, i);
                if (a[cnt] * b[i] < 0 or abs(a[cnt]) > abs(b[i])) {
                    // Albert win
                    for (int score = 0; score < n; score++) {
                        f[newMask][score + 1] += f[mask][score];
                    }
                } else {
                    for (int score = 0; score <= n; score++) {
                        f[newMask][score] += f[mask][score];
                    }
                }
            }
        }
    }
    cout << f[maxMask][m] << el;
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