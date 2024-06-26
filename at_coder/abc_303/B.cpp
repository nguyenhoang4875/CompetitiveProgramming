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
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 100 + 5;
int n, m;
int a[ms][ms];

void solve() {
    cin >> m >> n;
    For(i, 1, n) {
        For(j, 1, m) { cin >> a[i][j]; }
    }
    vector<set<int>> v(m + 1);
    For(i, 1, n) {
        For(j, 1, m) {
            if (j > 1) v[a[i][j]].insert(a[i][j - 1]);
            if (j < m) v[a[i][j]].insert(a[i][j + 1]);
        }
    }
    int ans = 0;
    For(i, 1, m) { ans += m - 1 - v[i].size(); }
    ans /= 2;
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}