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
int n, x;

void solve() {
    cin >> n >> x;
    vi a(n);
    for (auto &x : a) cin >> x;

    auto getSubsetSum = [&](int l, int r) {
        vi ret;
        int len = r - l + 1;
        int maxMask = (1 << len) - 1;
        for (int mask = 0; mask <= maxMask; mask++) {
            int sum = 0;
            for (int i = 0; i < len; i++) {
                if ((mask >> i) & 1) sum += a[i + l];
            }
            ret.push_back(sum % x);
        }
        return ret;
    };

    vi left = getSubsetSum(0, n / 2 - 1);
    vi right = getSubsetSum(n / 2, n - 1);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int ans = 0;
    for (auto e : left) {
        auto up = upper_bound(right.begin(), right.end(), x - e - 1);
        up--;
        ans = max(ans, *up + e);
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}