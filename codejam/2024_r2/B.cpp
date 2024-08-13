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
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }

const long long oo = 1e9, mod = 1e9 + 7;
const int ms = 10;
int n;
vector<vector<vector<int>>> d;
// int a[ms];

void solve() {
    cin >> n;

    vector<vvi> d = vector<vvi>(n + 1, vvi(n + 1, vi(n + 1)));

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> d[k][i][j];
            }
        }
    }

    int maxMask = (1LL << n) - 1;

    vvvi fm(maxMask + 1, vvi(maxMask + 1, vi(n + 1, oo)));
    vvvi fM(maxMask + 1, vvi(maxMask + 1, vi(n + 1, -oo)));
    fm[0][1][0] = 0;
    fM[0][1][0] = 0;

    for (int mask0 = 0; mask0 <= maxMask; mask0++) {
        for (int i = 0; i < n; i++) {
            if (!getBit(mask0, i)) {
                int newMask0 = setBit(mask0, i);
                for (int mask1 = 0; mask1 <= maxMask; mask1++) {
                    if (__builtin_popcount(mask0) + 1 != __builtin_popcount(mask1)) continue;
                    for (int j = 0; j < n; j++) {
                        if (getBit(mask1, j)) {
                            for (int k = 0; k < n; k++) {
                                if (getBit(mask1, k)) continue;
                                if (d[i][j][k] == 0) continue;

                                int newMask1 = setBit(mask1, k);
                                fm[newMask0][newMask1][k] = min(fm[newMask0][newMask1][k],
                                                                fm[mask0][mask1][j] + d[i][j][k]);
                                fM[newMask0][newMask1][k] = max(fM[newMask0][newMask1][k],
                                                                fM[mask0][mask1][j] + d[i][j][k]);
                            }
                        }
                    }
                }
            }
        }
    }
    int retMin = oo, retMax = -oo;

    for (int i = 0; i < n; i++) {
        int newMask = clearBit(maxMask, i);
        for (int j = 0; j < n; j++) {
            int t = d[i][j][0];
            if (t == 0) continue;
            retMin = min(retMin, fm[newMask][maxMask][j] + t);
            retMax = max(retMax, fM[newMask][maxMask][j] + t);
        }
    }
    if (retMin == oo) {
        retMin = retMax = 0;
    }
    cout << retMin << " " << retMax << el;
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