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
const int ms = 2e5 + 5;
int k, n;
int price[20][20];

void solve() {
    cin >> k >> n;
    ;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> price[i][j];
        }
    }

    vvi f(1 << k, vi(n + 1, oo));
    // f[i][j]: the minimum cost get mask: i that last j days for so far

    int maxMask = (1 << k) - 1;

    for (int d = 0; d < n; d++) {
        for (int mask = 0; mask <= maxMask; mask++) {
            f[mask][d] = f[mask][d - 1];
            for (int i = 0; i < k; i++) {
                if (getBit(mask, i)) {
                    int newMask = clearBit(mask, i);
                    f[mask][d] =
                        min(f[mask][d], d == 0 ? price[i][d] : f[newMask][d - 1] + price[i][d]);
                }
            }
        }
    }
    cout << f[maxMask][n - 1] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}