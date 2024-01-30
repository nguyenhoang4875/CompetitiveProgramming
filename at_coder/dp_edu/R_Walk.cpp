#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Walk
 * Solution: DP + matrix exponentiation
 */

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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 51;
int n, k;

struct Mat {
    int m[ms][ms];
    Mat() { memset(m, 0, sizeof(m)); }

    void identity() {
        for (int i = 0; i < ms; i++) {
            m[i][i] = 1;
        }
    }

    Mat operator*(const Mat& a) {
        Mat res;
        for (int i = 0; i < ms; i++) {
            for (int j = 0; j < ms; j++) {
                for (int k = 0; k < ms; k++) {
                    res.m[i][j] += m[i][k] * a.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

void solve() {
    Mat a, res;
    cin >> n >> k;
    For(i, 0, n - 1) {
        For(j, 0, n - 1) { cin >> a.m[i][j]; }
    }
    res.identity();

    while (k) {
        if (k & 1) res = res * a;
        k /= 2;
        a = a * a;
    }
    int ans = 0;
    For(i, 0, n - 1) {
        For(j, 0, n - 1) {
            ans += res.m[i][j];
            ans %= mod;
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}