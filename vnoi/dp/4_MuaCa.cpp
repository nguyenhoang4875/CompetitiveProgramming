#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

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
    vi a(n);
    for (auto &x : a) cin >> x;
    int sum = accumulate(all(a), 0);

    vi f(sum + 1, 0);  // f[i] can have sum equal i
    f[0] = 1;
    for (auto e : a) {
        for (int i = 1; i <= sum; i++) {
            if (i >= e) f[i] |= f[i - e];
        }
    }
    int ans = 0;
    For(i, 0, sum) {
        if (f[i]) ans++;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}