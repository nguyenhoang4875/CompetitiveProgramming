#include <bits/stdc++.h>

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

const long long oo = 1e9, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int M, C;
    cin >> M >> C;
    vvi price(C + 1, vi(25, 0));
    Rep(i, C) {
        cin >> price[i][0];
        For(j, 1, price[i][0]) cin >> price[i][j];
    }

    vvb can(C + 5, vb(M + 5, false));

    For(i, 1, price[0][0]) {
        if (M - price[0][i] >= 0) {
            can[0][M - price[0][i]] = true;
        }
    }

    For(idx, 1, C - 1) {
        Rep(b, M) if (can[idx - 1][b]) {
            For(k, 1, price[idx][0]) {
                if (b - price[idx][k] >= 0) can[idx][b - price[idx][k]] = true;
            }
        }
    }

    int save = -1;
    For(b, 0, M) {
        if (can[C - 1][b]) {
            save = b;
            break;
        }
    }
    if (save == -1) cout << "no solution" << el;
    else cout << M - save << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}