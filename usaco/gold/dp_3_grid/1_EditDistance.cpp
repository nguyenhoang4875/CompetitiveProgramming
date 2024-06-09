#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = sz(s1), m = sz(s2);
    vvi f(n + 1, vi(m + 1, oo));
    f[0][0] = 0;
    For(i, 0, n) {
        For(j, 0, m) {
            // delete i - 1 from the s1 string
            if (i > 0) f[i][j] = min(f[i][j], f[i - 1][j] + 1);

            // add j - 1 from the s2 string
            if (j > 0) f[i][j] = min(f[i][j], f[i][j - 1] + 1);

            // change to make s1[i - 1] == s2[j -1];
            if (i > 0 and j > 0) {
                int newCost = f[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]);
                f[i][j] = min(f[i][j], newCost);
            }
        }
    }
    cout << f[n][m] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}