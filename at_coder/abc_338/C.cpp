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
const int ms = 10 + 5;
int n;
int q[ms], a[ms], b[ms];

void solve() {
    cin >> n;
    For(i, 1, n) cin >> q[i];
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];

    int mx = 1e6;
    int ans = 0;
    for (int numA = 0; numA <= mx; numA++) {
        int numB = oo;
        bool ok = true;
        For(i, 1, n) {
            if (q[i] < numA * a[i]) {
                ok = false;
                break;
            }
            if (b[i] > 0) {
                numB = min(numB, (q[i] - numA * a[i]) / b[i]);
            }
        }
        if (ok) ans = max(ans, numA + numB);
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}