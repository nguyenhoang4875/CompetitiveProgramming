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
int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }
const int oo = 2e18, mod = 1e9 + 7;
const int ms = 20 + 5;
int n;
int a[ms][ms];

void solve() {
    cin >> n;
    For(i, 0, n - 1) {
        For(j, 0, n - 1) { cin >> a[i][j]; }
    }

    vi f(1 << n, 0);

    int maxMask = (1 << n) - 1;
    f[0] = 1;
    for (int mask = 0; mask <= maxMask; mask++) {
        int num = __builtin_popcount(mask);
        for (int pos = 0; pos < n; pos++) {
            if (!getBit(mask, pos) and a[num][pos]) {
                int newMask = setBit(mask, pos);
                f[newMask] += f[mask];
                f[newMask] %= mod;
            }
        }
    }
    // for(int i = 0; i < 1 << n; i++) {
    //     for(int j = 5; j >=0; j--) {
    //         cout << getBit(i, j);
    //     }
    //     cout << " " << f[i] << el;
    // }
    cout << f[maxMask] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}