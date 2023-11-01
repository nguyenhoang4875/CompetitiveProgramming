#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/group/AzS2VFYWhz/contest/482326/problem/G
 * 
 * Solution: a[u] - a[v] >= b[u] - b[v] <=> a[u] - b[u] >= a[v] - b[v] => save in c as pair
 *  - Sort value c by descending val and index asc
 * 
 * TC: O(n)
 * MC: O(n)
 * 
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
int a[ms], b[ms];
int n;

void solve() {
    cin >> n;

    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];


    // a[u] - a[v] >= b[u] - b[v] <=> a[u] - b[u] >= a[v] - b[v]
    vii c;
    For(i, 1, n) {
        int x = a[i] - b[i];
        c.pb({x, i});
    }
    // sort desc first and then asc second
    sort(all(c),[&] (pii p1, pii p2) {
        if(p1.F == p2.F) return p1.S < p2.S;
        return p1.F > p2.F;
    });

    int max_val = c.front().F;
    vi ans;
    for(auto [f, s]: c) {
        if(f == max_val) {
            ans.pb(s);
        } else break;
    }
    cout << ans.size() << el;
    for(auto e: ans) cout << e << " ";
    cout << el;
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