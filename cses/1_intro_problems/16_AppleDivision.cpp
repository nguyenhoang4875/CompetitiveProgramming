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
const int ms = 25;
int n;
int a[ms];

void solve() {
    cin >> n;
    int total = 0;
    For(i, 0, n - 1) {
        cin >> a[i];
        total += a[i];
    }

    int ans = oo;
    For(i, 0, (1 << n) - 1) {
        int sum = 0;
        Ford(j, n - 1, 0) {
            if((i >> j) & 1) {
                sum += a[j];
            }
        }
        // cout << "sum = " << sum << '\n';
        ans = min(ans, abs(total - 2 * sum));
    }
    cout << ans << "\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve();
    int b[8];
    iota(b, b + 8, 0);


    return 0;
}