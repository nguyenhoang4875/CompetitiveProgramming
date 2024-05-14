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

int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    vector<int> d(m);
    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }
    vector<vector<int>> c;
    c.resize(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> c1;
    c1.resize(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = (t.begin() + i) - lower_bound(t.begin(), t.end(), t[i] - d[j] + 1) + 1;
            c1[i][j] = upper_bound(t.begin(), t.end(), t[i] + d[j] - 1) - (t.begin() + i);
            // cout << i << " " << j << " " << c[i][j] << endl;
        }
    }
    vector<vector<int>> f;
    f.resize(n + 1, vector<int>(1 << m, 0));

    // f[i][j]: max cover point
    // i-th d
    // j: mask of t
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < (1 << m); j++) {
    //         f[i][j] = f[i - 1][j];
    //         for (int x = 0; x < m; x++) {
    //             if (getBit(j, x)) {
    //                 int k = c[i - 1][x];
    //                 f[i][j] = max(f[i][j], f[i - k][clearBit(j, x)] + k);
    //             }
    //         }
    //     }
    // }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << m); j++) {
            f[i + 1][j] = max(f[i + 1][j], f[i][j]);
            for (int x = 0; x < m; x++) {
                if (!getBit(j, x)) {
                    int k = c1[i][x];
                    if (i + k <= n)
                        f[i + k][setBit(j, x)] = max(f[i + k][setBit(j, x)], f[i][j] + k);
                }
            }
        }
    }
    cout << n - f[n][(1 << m) - 1];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}