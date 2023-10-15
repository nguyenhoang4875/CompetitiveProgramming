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

const int oo = 1e18;
int const ms = 18;
int sz;
int b[ms], c[ms];
int mod;

struct Mat {
    int m[ms][ms];
    Mat() { memset(m, 0, sizeof(m)); }

    void identity() {
        for (int i = 0; i < sz + 1; i++) {
            m[i][i] = 1;
        }
    }

    Mat operator*(Mat a) {
        Mat res;
        for (int i = 0; i < sz + 1; i++) {
            for (int j = 0; j < sz + 1; j++) {
                for (int k = 0; k < sz + 1; k++) {
                    res.m[i][j] += m[i][k] % mod * (a.m[k][j] % mod) % mod;
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

int cal(int n) {
    if (n < sz) {
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            ans += b[i] % mod;
            ans %= mod;
        }
        return ans;
    };
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
    // for (int i = 0; i < sz; i++) t.m[0][i] = c[i];
    // for (int i = 1; i < sz; i++) t.m[i][i - 1] = 1;
    t.m[0][0] = 1;
    for(int i = 1; i < sz + 1; i++) t.m[0][i] = c[i - 1];
    for(int i = 1; i < sz + 1; i++) t.m[1][i] = c[i - 1];
    for(int i = 2; i < sz + 1; i++) t.m[i][i - 1] = 1;


    for(int i = 0; i < sz + 1; i++) {
        for(int j = 0; j < sz + 1; j++) {
            cout << t.m[i][j] << " ";
        }
        cout << '\n';
    }

    n = n + 1 - sz;  // + 1 by base-index 0
    while (n) {
        if (n & 1) res = res * t;
        t = t * t;
        n /= 2;
    }
    int ans = 0;
    for (int i = 0; i < sz + 1; i++) {
        // ai = c1a(i-1) + c1a(i-2) ... + cka(i-k)
        ans += res.m[0][i] % mod * (b[sz - 1 - i] % mod) % mod;  
        ans %= mod;
    }
    return ans;
}

void solve() {
    cin >> sz;
    for (int i = 0; i < sz; i++) {
        cin >> b[i];
        // b[i] %= mod;
    }
    for (int i = 0; i < sz; i++) {
        cin >> c[i];
        // c[i] %= mod;
    }
    int m, n;
    cin >> m >> n >> mod;
    m--, n--;
    if(n < sz) {
        int ans = 0;
        for(int i = m; i <= n; i++) {
            ans += b[i] % mod;
            ans %= mod;
        }
        cout << ans << '\n';
        return;
    }

    int ans = (cal(n) % mod - cal(m - 1) % mod + mod) % mod;
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) solve();
    return 0;
}