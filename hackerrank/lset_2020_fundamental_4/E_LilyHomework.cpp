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
int n;
/**
 * @param: vector a, bool: desc (default: false)
 * if(desc == tre) minSwap to get the array sorted descending
 * @return: minimum swap to get array sorted
 * TC: O(n log n)
 */
int minSwap(vector<int>& a, bool desc = false) {
    int n = a.size();
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
        vp.push_back({a[i], i});
    }
    if (desc)
        sort(vp.rbegin(), vp.rend());
    else
        sort(vp.begin(), vp.end());

    vector<bool> seen(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (seen[i] || vp[i].second == i) continue;

        int cycleSize = 0;
        int j = i;
        while (!seen[j]) {
            seen[j] = true;
            // move to the nex mode
            j = vp[j].second;
            cycleSize++;
        }
        if (cycleSize > 0) ans += cycleSize - 1;
    }
    return ans;
}

void solve() {
    cin >> n;
    vi a(n);
    For(i, 0, n - 1) cin >> a[i];
    cout << min(minSwap(a), minSwap(a, 1)) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}