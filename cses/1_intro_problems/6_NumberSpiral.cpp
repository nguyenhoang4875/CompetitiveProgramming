#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it,x) for(auto it = x.begin(); it != x.end(); ++it)

using namespace std;

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
int n;

void solve() {
    int x, y;
    cin >> y >> x;
    int z = max(y, x);
    int z2 = (z - 1) * (z - 1);
    int ans;
    if(z & 1) {
        if(y == z) {
            ans = z2 + x;
        } else {
            ans = z2 + 2 * z - y;
        } 
    } else {
        if(x == z) {
            ans = z2 + y;
        } else {
            ans = z2 + 2*z - x;
        }
    }
    cout << ans << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcs;
    cin >> tcs;
    while(tcs--) solve();
    return 0;
}