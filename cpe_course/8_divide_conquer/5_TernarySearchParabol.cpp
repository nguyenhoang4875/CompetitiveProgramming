#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Ternary Search:
 * Let array: ascending then descending ex: [1, 2, 5, 6, 4, 3, 1]
 * Find in the range: [l, r]
 *  mid1 = (2l + r) / 3;
 *  mid2 = (2r + l) / 3;
 *  if(f(mid1) < f(mid2)) => update range: [mid1, r] (1)
 *  if(f(mid1) > f(mid2)) => update range: [l, mid2]
 *  if(f(mid1) == f(mid2)) => update range: [mid1, r] or [l, mid2]
 * Note: change (1) to f(mid1) > f(mid2) if array descending then ascending
 *
 * TC: O(log(3/2) n)
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
const int ms = 1e5 + 5;
const double esp = 1e-6;
int n;

double f(double x) { return -(x * x) + 4 * x; }

double ternarySearch(double l, double r) {
    while (r - l > esp) {
        double mid1 = (2 * l + r) / 3;
        double mid2 = (l + 2 * r) / 3;
        if (f(mid1) < f(mid2)) {  // change < to > if a > 0 (a * x * x)
            l = mid1;
        } else {
            r = mid2;
        }
    }
    return l;
}

void solve() {
    double l = -100, r = 100;
    cout << ternarySearch(l, r) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}