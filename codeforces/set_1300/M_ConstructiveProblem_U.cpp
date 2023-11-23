#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/group/AzS2VFYWhz/contest/482326/problem/M
 * Solution: Brute force
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

// calc the mex value
int calc(vi v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end()); // delete duplicate value after sort
    int n = sz(v);
    For(i, 0, n - 1) if (v[i] != i) return i;
    return n;
}

void solve() {
    cin >> n;
    vi a(n);
    map<int, int> leftOcc, rightOcc;
    For(i, 0, n - 1) {
        cin >> a[i];
        rightOcc[a[i]] = i;
        if (!leftOcc.count(a[i])) leftOcc[a[i]] = i;
    }
    int mex = calc(a);
    if (leftOcc.count(mex + 1)) {
        // if mex+1 in the array: replace all value mex+1 to mex
        int l = leftOcc[mex + 1], r = rightOcc[mex + 1];
        For(i, l, r) a[i] = mex;
        int mx = calc(a); // re-calc mex value
        if (mx == mex + 1) {
            cout << "Yes\n";
        } else
            cout << "No\n";
        return;
    }
    // not have value: mex+1 in array
    For(i, 0, n - 1) {
        // have any value a[i] > mex => a[i] = mex
        // have at least two value a[i] = a[j]  < mex => a[i] = mex
        if (a[i] > mex || leftOcc[a[i]] != rightOcc[a[i]]) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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