#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/17280
 * Solution: Binary search + greedy
 *
 * TC: O(M log M + (M + N) log N)
 * MC: O(N + M)
 */

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
const int ms = 2e5 + 5;
int n, m;
vi x, y, z;

int match() {
    multiset<int> ms(all(x));
    vi idx(m);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) {
        // if(z[i] == z[j]) return y[i] > y[j]; // sort idx by asc z[i] then asc y[i]
        return z[i] < z[j];
    });
    int ans = 0;
    for (auto i : idx) {
        auto it = ms.lower_bound(y[i]);  // find lowest y satisfaction
        if (it == ms.end() || *it > z[i]) continue;
        ans++;
        ms.erase(it);
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    x = vi(n);
    For(i, 0, n - 1) cin >> x[i];
    y = vi(m);
    z = vi(m);
    For(i, 0, m - 1) {
        cin >> y[i];
        cin >> z[i];
    }
    cout << match() << el;
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