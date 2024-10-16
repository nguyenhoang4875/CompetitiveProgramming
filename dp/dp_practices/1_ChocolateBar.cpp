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
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 1e9, mod = 1e9 + 7;
const int ms = 2e5 + 5;
const int N = 35, K = 55;
int f[N][N][K];

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int l = 0; l < K; l++) {
                if (l == 0 or l == i * j) {
                    f[i][j][l] = 0;
                    continue;
                }

                f[i][j][l] = oo;

                // split horizontal
                for (int i1 = 0; i1 < i; i1++) {
                    for (int l1 = 0; l1 < l; l1++) {
                        int i2 = i - i1, l2 = l - l1;
                        f[i][j][l] = min(f[i][j][l], f[i1][j][l1] + f[i2][j][l2] + j * j);
                    }
                }

                // split vertical
                for (int j1 = 0; j1 < j; j1++) {
                    for (int l1 = 0; l1 < l; l1++) {
                        int j2 = j - j1, l2 = l - l1;
                        f[i][j][l] = min(f[i][j][l], f[i][j1][l1] + f[i][j2][l2] + i * i);
                    }
                }
            }
        }
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << f[n][m][k] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}