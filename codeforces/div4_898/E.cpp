#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
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
const int ms = 2e5 + 5;
int n, x;
int a[ms];

bool check(int val) {
    int sum = 0;
    For(i, 1, n) {
        if(val > a[i]) {
            sum += val - a[i];
        }
        if(sum > x) return false;
    }
    return true;
}

void solve() {
    cin >> n >> x;
    For(i, 1, n) cin >> a[i];

    int l = 0, r = oo;
    int ans = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
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