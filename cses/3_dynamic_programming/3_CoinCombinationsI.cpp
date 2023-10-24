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
const int ms = 1e2 + 5;
int n, target;
int a[ms];


void solve() {
    cin >> n >> target;
    For(i, 1, n) cin >> a[i];


    vi dp(target + 1, 0);
    dp[0] = 1;

    For(i, 1, target) {
        For(j, 1, n) {
            if(i - a[j] >= 0) {
                dp[i] +=  dp[i - a[j]];
                dp[i] %= mod;
            }
        }
    }
    if(dp[target] != oo) cout << dp[target] << '\n';
    else cout << "-1\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}