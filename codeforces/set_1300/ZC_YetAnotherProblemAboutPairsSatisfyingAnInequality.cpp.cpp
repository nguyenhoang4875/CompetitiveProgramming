#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/group/AzS2VFYWhz/contest/482326/problem/ZC
 * Solution: 
 * - ai< i < aj < j  <=> ai < i and and i < aj and aj < i
 * - remove all element that a[i] > i
 * - binary seach to count i < a[j]
 * 
 * TC: O(n * log n)
 * MC: O(n)
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
int n;
int a[ms];


void solve() {
    cin >> n;
    For(i, 1, n) {
        cin >> a[i];
    }
    vi v;
    int ans = 0;
    For(i, 1, n) {
        if(a[i] >= i) continue;
        ans += (int) (lower_bound(all(v), a[i]) - v.begin());
        v.pb(i);
    }
    cout << ans << el;

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