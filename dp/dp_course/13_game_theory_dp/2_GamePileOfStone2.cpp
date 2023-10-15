#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://www.codechef.com/problems/GAMEOFPILES1
 */

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
const string A = "CHEF";
const string B = "CHEFINA";
const int ms = 1e5 + 5;
int n;
int a[ms];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    if (a[1] == 1) {
        cout << A << '\n';
        return;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += a[i] - 2;
    }
    if (cnt & 1) {
        cout << A << '\n';
    } else
        cout << B << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) solve();
    return 0;
}