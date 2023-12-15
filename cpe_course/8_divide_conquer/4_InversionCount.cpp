#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Given an array containing integers, you need to count
 * the total number of inversions.
 * Inversion: two elements a[i] and a[j] form an inversion if
 * a[i] > a[j] and i < j
 *
 * Solution: Using merge sort:
 *  ans = count_p1 + count_p2 + cout_cross_inversion
 *  count cross inversion = mid - i + 1
 *
 * TC: O(n log n)
 * MC: O(n log n)
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

int merge(vi &a, int s, int e) {
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    vi temp;
    int cnt = 0;
    while (i <= mid && j <= e) {
        if (a[i] <= a[j])
            temp.pb(a[i++]);
        else {
            cnt += mid - i + 1;
            temp.pb(a[j++]);
        }
    }

    // for the rest elements in left part
    while (i <= mid) temp.pb(a[i++]);

    // for the rest elements in right part
    while (j <= e) temp.pb(a[j++]);

    // copy to original array
    int k = 0;
    for (int i = s; i <= e; i++) {
        a[i] = temp[k++];
    }
    return cnt;
}

int inversionCount(vi &a, int s, int e) {
    // base case
    if (s >= e) {
        return 0;
    }

    // recursion case
    int mid = (s + e) / 2;
    int c1 = inversionCount(a, s, mid);
    int c2 = inversionCount(a, mid + 1, e);
    int ci = merge(a, s, e);
    return c1 + c2 + ci;
}

void solve() {
    cin >> n;
    vi a(n);
    for (auto &x : a) cin >> x;
    cout << inversionCount(a, 0, n - 1) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}