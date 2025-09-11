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

// O(n^3)
int cutBu(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> f(n + 1, vector<int>(n + 1, oo));
    for (int i = 1; i < n; i++) f[i - 1][i] = 0;

    for (int l = n - 1; l >= 0; --l) {
        for (int r = l; r < n; ++r) {
            for (int i = l + 1; i < r; ++i) {
                f[l][r] = min(f[l][r], f[l][i] + f[i][r] + a[r] - a[l]);
            }
        }
    }
    return f[0][n - 1];
}

void solve() {
    while (true) {
        int l;
        cin >> l;
        if (!l) return;

        int n;
        cin >> n;
        vi a = {0};

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.pb(x);
        }

        a.pb(l);
        n = a.size();

        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));

        // O(n^3)
        function<int(int, int)> cutTd = [&](int l, int r) {
            if (l + 1 == r) return 0;  // can not cutting

            int& ans = memo[l][r];
            if (ans != -1) return memo[l][r];

            ans = oo;
            for (int i = l + 1; i < r; ++i) {
                ans = min(ans, cutTd(l, i) + cutTd(i, r) + a[r] - a[l]);
            }
            return ans;
        };

        cout << "The minimum cutting is ";
        // cout << cutBu(a) << "." << el;
        cout << cutTd(0, n - 1) << "." << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}