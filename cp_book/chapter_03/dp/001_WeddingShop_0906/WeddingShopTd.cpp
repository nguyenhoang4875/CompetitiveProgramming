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

    vvi memo(C + 5, vi(M + 5, -1));

    function<int(int, int)> f = [&](int idx, int b) {
        if (b < 0) return (int)-1e9;
        if (idx == C) return M - b;  // got ans

        int &ans = memo[idx][b];
        if (ans != -1) return ans;

        for (int k = 1; k <= price[idx][0]; ++k) {
            ans = max(ans, f(idx + 1, b - price[idx][k]));
        }
        return ans;
    };

    int ans = f(0, M);
    if (ans < 0) cout << "no solution" << el;
    else cout << ans << el;
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