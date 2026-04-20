#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

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

void solve() {
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    Rep(i, n) Rep(j, m) cin >> a[i][j];

    if (n > m) {
        vvi b(m, vi(n));
        Rep(i, m) {
            Rep(j, n) { b[i][j] = a[j][i]; }
        }
        swap(n, m);
        swap(a, b);
    }
    vector<vvi> f(n, vvi(n, vi(20, 0)));

    For(r1, 0, n - 1) {
        For(r2, r1 + 1, n - 1) {
            For(c, 0, m - 1) {
                int sum = a[r1][c] + a[r2][c];
                f[r1][r2][sum]++;
            }
        }
    }

    int cnt = 0;
    For(r1, 0, n - 1) {
        For(r2, r1 + 1, n - 1) {
            For(v1, 2, 18) {
                int v2 = 20 - v1;
                if (v2 < v1) break;
                if (v2 == v1) {
                    int val = f[r1][r2][v1];
                    cnt += val * (val - 1) / 2;
                } else {
                    cnt += f[r1][r2][v1] * f[r1][r2][v2];
                }
            }
        }
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}