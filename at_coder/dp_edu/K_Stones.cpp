#include <bits/stdc++.h>
#define int long long
#define pb push_back

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
int n, k;
int a[105];
int dp[100005];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int stone = 0; stone <= k; stone++) {
        for (int i = 1; i <= n; i++) {
            if (stone >= a[i] && !dp[stone - a[i]]) {
                dp[stone] = true;
            }
        }
    }

    if (dp[k]) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}