#include <bits/stdc++.h>
#define int long long

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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

int f[27][27][352] = {0};

void init() {
    f[0][0][0] = 1;
    for (int len = 1; len <= 26; ++len) {
        for (int ls = 0; ls <= len; ++ls) {
            for (int s = 0; s < 352; ++s) {
                f[len][ls][s] = f[len - 1][ls][s];
                if (ls > 0 and s >= len) f[len][ls][s] += f[len - 1][ls- 1][s - len];
            }
        }
    }
}

void solve() {
    init();
    int tc = 0;
    int l, s;
    while (true) {
        cin >> l >> s;
        if (!l and !s) return;

        cout << "Case " << ++tc << ": ";
        if (l > 26 or s >= 352) {
            cout << 0 << el;
            continue;
        }
        int ans = f[26][l][s];

        cout << ans << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}