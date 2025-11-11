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
const int ms = 70;

int memo[ms][ms][2];
int cntWay(int n, int s, bool l) {
    if (n == 0 and s == 0) return memo[n][s][l] = 1;

    if (s > n or n < 0 or s < 0) return 0;

    int& ans = memo[n][s][l];
    if (ans != -1) return ans;
    ans = cntWay(n - 1, s - l, true) + cntWay(n - 1, s, false);
    return ans;
};

void solve() {
    int n, s;
    while (true) {
        cin >> n >> s;
        memset(memo, -1, sizeof memo);
        if (n < 0 and s < 0) return;
        cout << cntWay(n, s, true) << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}