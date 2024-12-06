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
const int ms = 1e3 + 5;
int n, k;
int a[ms], b[ms], c[ms];

void solve() {
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];

    Rof(i, n, 1) {
        c[i] = min(k, a[i] / b[i]);
        k -= c[i];
    }
    if (k == 0) {
        For(i, 1, n) cout << c[i] << " ";
        cout << el;
        return;
    }

    For(i, 1, n) cout << 0 << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}