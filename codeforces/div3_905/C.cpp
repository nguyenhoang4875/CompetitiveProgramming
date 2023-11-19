#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it,x) for(auto it = x.begin(); it != x.end(); ++it)

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
int n, k;
int a[ms];


void solve() {
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];

    int ans = oo;
    int sum = 1;
    int cnt2 = 0;
    For(i, 1, n) {
        // sum *= i;
        // sum %= k;
        if(a[i] % 2 == 0) cnt2++;
        if(a[i] % k == 0) {
            ans = 0;
            cout << "0\n";
            return;
        }
        ans = min({ans, k -  a[i] % k});
    }
    int cnt4 = 0;
    if(k == 4) {
        if(cnt2 >= 2) {
            cout << "0\n";
        } else if(cnt2 == 1) {
            cout << "1\n";
        } else {
            ans = min(2LL, ans);
            cout << ans << '\n';
        }
        return;
    }
    cout << ans << '\n';

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