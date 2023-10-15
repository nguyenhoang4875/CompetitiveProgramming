#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/SEQ/
 * Solution: Matrix Exponentiation
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9;
int const ms = 11;
int sz;
int b[ms], c[ms];
int n;

struct Mat {
    int m[ms][ms];
    Mat() { memset(m, 0, sizeof(m)); }

    void identity() {
        for (int i = 0; i < sz; i++) {
            m[i][i] = 1;
        }
    }

    Mat operator*(Mat a) {
        Mat res;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                for (int k = 0; k < sz; k++) {
                    res.m[i][j] += m[i][k] * a.m[k][j] % mod;
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

int cal(int n) {
    if (n < sz) return b[n];
    Mat res;
    res.identity();
    /*
    T.m:
        c1 c2 ... ck
        1  0  ... 0
        0  1  ... 0
        ...........
        0  0 .... 1

    */
    Mat t;
    for (int i = 0; i < sz; i++) t.m[0][i] = c[i];
    for (int i = 1; i < sz; i++) t.m[i][i - 1] = 1;

    n = n + 1 - sz;  // + 1 by base-index 0
    while (n) {
        if (n & 1) res = res * t;
        t = t * t;
        n /= 2;
    }
    int ans = 0;
    for (int i = 0; i < sz; i++) {
        ans += res.m[0][i] % mod * (b[sz - 1 - i]) %
               mod;  // ai = c1a(i-1) + c1a(i-2) ... + cka(i-k)
        ans %= mod;
    }
    return ans;
}

void solve() {
    cin >> sz;
    for (int i = 0; i < sz; i++) {
        cin >> b[i];
        b[i] %= mod;
    }
    for (int i = 0; i < sz; i++) {
        cin >> c[i];
        c[i] %= mod;
    }
    cin >> n;
    n--;
    cout << cal(n) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) solve();
    return 0;
}