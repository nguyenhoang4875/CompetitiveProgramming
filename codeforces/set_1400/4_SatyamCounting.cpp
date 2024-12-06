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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

void solve() {
    cin >> n;
    vector<set<int>> vy(2);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vy[y].insert(x);
    }

    int n0 = vy[0].size();
    int n1 = vy[1].size();
    int ans = 0;
    for (auto x : vy[0]) {
        if (vy[1].count(x)) {
            ans += n0 - 1;
            ans += n1 - 1;
        }
    }

    for (auto x : vy[0]) {
        if (vy[0].count(x + 2) and vy[1].count(x + 1)) {
            ans++;
        }
    }
    for (auto x : vy[1]) {
        if (vy[1].count(x + 2) and vy[0].count(x + 1)) {
            ans++;
        }
    }

    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}