#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/group/AzS2VFYWhz/contest/482326/problem/ZD
 * Solution: Brute force
 * - if array a have more than two positive or negative values => NO
 * - only take max two element 0
 * - else brute force for remain element: maximum 6
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
const int ms = 1e5 + 5;
int n;

void solve() {
    cin >> n;
    vi a;
    vi pos, neg;
    For(i, 1, n) {
        int x;
        cin >> x;
        if (x > 0)
            pos.pb(x);
        else if (x < 0)
            neg.pb(x);
        else {
            if (a.size() < 2) a.pb(x);
        }
    }
    if (sz(pos) > 2 || sz(neg) > 2) {
        cout << "NO\n";
        return;
    }
    for (auto e : pos) a.pb(e);
    for (auto e : neg) a.pb(e);


    n = sz(a);
    For(i, 0, n - 3) {
        For(j, i + 1, n - 2) {
            For(k, j + 1, n - 1) {
                bool found = false;
                For(l, 0, n - 1) {
                    if(a[i] + a[j] + a[k] == a[l]) {
                        found = true;
                    }
                }
                if(!found) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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