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
const int ms = 2e5 + 5;

int w, h, n, A, B;
int x[ms], y[ms];
int a[ms], b[ms];

void solve() {
    cin >> w >> h;
    cin >> n;
    For(i, 1, n) { cin >> x[i] >> y[i]; }
    cin >> A;
    For(i, 1, A) cin >> a[i];

    cin >> B;
    For(i, 1, B) cin >> b[i];

    a[A + 1] = w;
    b[B + 1] = h;

    map<pii, int> mp;
    For(i, 1, n) {
        int xx = *lower_bound(a + 1, a + A + 2, x[i]);
        int yy = *lower_bound(b + 1, b + B + 2, y[i]);
        mp[{xx, yy}]++;
    }
    int m = oo, M = 0;
    for (auto x : mp) {
        m = min(m, x.S);
        M = max(M, x.S);
    }
    if (mp.size() < (A + 1) * (B + 1)) m = 0;
    cout << m << " " << M << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}