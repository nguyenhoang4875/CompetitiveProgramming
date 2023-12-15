#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Quick select k-th min in the array
 * Solution: Using pivot, partition like quick sort
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
const int ms = 1e5 + 5;
int n;

int partition(vi& a, int s, int e) {
    int pivot = a[e];
    int i = s;
    for (int j = s; j < e; j++) {
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[e]);
    return i;
}

int quickSelect(vi& a, int s, int e, int k) {
    int p = partition(a, s, e);
    if (p == k)
        return a[p];
    else if (k < p)
        return quickSelect(a, s, p - 1, k);
    return quickSelect(a, p + 1, e, k);
}

void solve() {
    int k;
    cin >> n >> k;
    vi a(n);
    for (auto& x : a) cin >> x;
    cout << quickSelect(a, 0, n - 1, --k) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}