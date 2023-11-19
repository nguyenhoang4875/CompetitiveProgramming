#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/group/AzS2VFYWhz/contest/482326/problem/X
 * Solution: brute force
 * - if(a[i] + a[j] == 1) => make a segment[i, j]
 * - else make two segments: [i, i], [j, j]
 * 
 * TC: O(n)
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
    int sum = 0;
    For(i, 1, n) {
        cin >> a[i];
    }
    if(n&1) {
        cout << "-1\n";
        return;
    }
    vi ans;
    For(i, 1, n - 1) {
        if(a[i] - a[i + 1] == 0) {
            ans.pb(i);
            ans.pb(i + 1);
        } else {
            ans.pb(i);
            ans.pb(i);
            ans.pb(i + 1);
            ans.pb(i + 1);
        }
        i++;
    }
    cout << sz(ans) / 2 << el;
    For(i, 0, sz(ans) - 1) {
        cout << ans[i] << " ";
        if(i&1) cout << el;
    }
    
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