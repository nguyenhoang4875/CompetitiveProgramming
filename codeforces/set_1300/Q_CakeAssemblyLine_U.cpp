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
const int ms = 1e5 + 5;
int n, w, h;
int a[ms], b[ms];


void solve() {
    cin >> n >> w >> h;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];

    int minShift = -oo; // left side
    int maxShift = oo; // right side
    // (b[i] + h − w)− a[i] <=  p <= (b[i]− h+ w)− a[i]
    // check if p is exist
    For(i, 1, n) {
        minShift = max(minShift, b[i] + h - (a[i] + w));
        maxShift = min(maxShift, b[i] - h - (a[i] - w));
    }
    if(minShift <= maxShift) {
        cout << "YES\n";
    } else cout << "NO\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}