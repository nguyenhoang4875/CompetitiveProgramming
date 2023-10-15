#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

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
const int sz = 2;
int n;

struct Mat {
    int m[sz][sz];
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
                    res.m[i][j] += m[i][k] * a.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

int fib(int n) {
    Mat res;
    res.identity();
    /*
    T.m:
        1 1
        1 0
    */
    Mat t;
    t.m[0][0] = t.m[0][1] = t.m[1][0] = 1;

    if (n <= 2) return 1;

    n -= 2;
    while (n) {
        if (n & 1) res = res * t;
        t = t * t;
        n /= 2;
    }
    return (res.m[0][0] + res.m[0][1]) % mod;
}

void solve() {
    cin >> n;
    cout << fib(n);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}