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

// O(n^2)
int cutKnuthBu(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> f(n + 1, vector<int>(n + 1, oo));
    vector<vector<int>> opt(n + 1, vector<int>(n + 1));
    for (int i = 1; i < n; i++) {
        f[i - 1][i] = 0;
        opt[i - 1][i] = i;
    }

    auto c = [&](int i, int j) {
        return a[j] - a[i];
    };

    for (int l = n - 2; l >= 0; --l) {
        for (int r = l + 1; r < n; ++r) {
            for (int k = opt[l][r - 1]; k <= min(r - 1, opt[l + 1][r]); ++k) {
                int value = f[l][k] + f[k][r] + c(l, r);
                if (value < f[l][r]) {
                    f[l][r] = value;
                    opt[l][r] = k;
                }
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
        vector<vector<int>> opt(n + 1, vector<int>(n + 1));

        // O(n^2)
        function<int(int, int)> cutKnuthTd = [&](int l, int r) {
            if (l + 1 >= r) {
                opt[l][r] = r;
                return 0;
            }

            int& ans = memo[l][r];
            if (ans != -1) return memo[l][r];

            ans = oo;
            cutKnuthTd(l, r - 1);
            cutKnuthTd(l + 1, r);
            for (int k = opt[l][r - 1]; k <= min(r - 1, opt[l + 1][r]); ++k) {
                assert(k < n);
                assert(k >= 0);
                int value = cutKnuthTd(l, k) + cutKnuthTd(k, r) + a[r] - a[l];
                if (ans > value) {
                    ans = value;
                    opt[l][r] = k;
                }
            }
            return ans;
        };

        cout << "The minimum cutting is ";
        // cout << cutKnuthBu(a) << "." << el;
        cout << cutKnuthTd(0, n - 1) << "." << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}