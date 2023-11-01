#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/gym/482326/problem/I
 * Solution: Ad-hod
 *  - Two adjust element can not to be a sum
 *   - Sum all odd index and even index then find max of them
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
    int maxVal = -oo;
    For(i, 1, n) {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }
    if(maxVal < 0) {
        cout << maxVal << el;
        return;
    }

    int sum1 = 0, sum2 = 0;
    For(i, 1, n) {
        if(i & 1) {
            sum1 += max(a[i], 0LL);
        } else sum2 += max(a[i], 0LL);
    }
    cout << max(sum1, sum2) << el;
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