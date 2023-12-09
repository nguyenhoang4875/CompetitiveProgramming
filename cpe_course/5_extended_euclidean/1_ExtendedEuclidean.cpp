#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: ax + by = gcd(a, b) => Find the integer x, y satisfaction
 * 
 * Solution: Extended Euclidean algorithm
 * TC: O(log n)
 * MC: O(1)
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

// Euclid's algorithm
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

// Extended Euclid's algorithm: ax + by = gcd(a, b)
pair<int, int> extendedGcd(int a, int b) {
    if (b == 0) {
        // return value of x and y
        return {1, 0};
    }
    pair<int, int> ans = extendedGcd(b, a % b);

    // after recursive call is over
    int xx = ans.first;
    int yy = ans.second;

    int x = yy;
    int y = xx - a / b * yy;
    return {x, y};
}

vector<int> extendedGcd2(int a, int b) {
    if (b == 0) {
        // return value of x and y
        return {1, 0, a};
    }
    vector<int> ans = extendedGcd2(b, a % b);

    // after recursive call is over
    int xx = ans[0];
    int yy = ans[1];
    int gcd = ans[2];

    int x = yy;
    int y = xx - a / b * yy;
    return {x, y, gcd};
}

void solve() {
    int a, b;
    cin >> a >> b;

    // ax + by = gcd(a, b)
    pii ans = extendedGcd(a, b);
    cout << ans.first << " " << ans.second << el;

    vi ans2 = extendedGcd2(a, b);
    cout << ans2[0] << " " << ans2[1] << " " << ans2[2] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}