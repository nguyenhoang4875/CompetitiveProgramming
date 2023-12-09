#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Diophantine Equation: Polynomial equation in two or more unknowns,
 *  such that only integral solution are required.
 * Problem: ax + by = c => Determine the equation has a solution
 *  such that x and y are both integral solution
 *
 * Solution: ax + by = c
 *  g = gcd(a, b)
 *  if(c % g != 0) => No solution
 *  else
 *  c = k * gcd(a, b)
 *  let:  x' = x / k, y' = y/k
 *  => a * (k * x') + b*(k * y') = k*gcd(a,b)
 *  => a * x' + b*y' = gcd(a, b) (Extended euclidean algorithm)
 *
 * Let x0, y0 is a solution by using extended euclidean
 * The family solution is:
 *  x = x0 - b/gcd(a, b) * t
 *  y = y0 - a/gcd(a, b) * t
 *  t is an integer
 *
 * TC: O(log n)
 * MC: O(1)
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
int n;

vector<int> extendedGcd(int a, int b) {
    if (b == 0) {
        return {1, 0, a};
    }
    vi ans = extendedGcd(b, a % b);
    int xx = ans[0];
    int yy = ans[1];

    int x = yy;
    int y = xx - (a / b) * yy;
    int gcd = ans[2];
    return {x, y, gcd};
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    vi ans = extendedGcd(a, b);
    if(c % ans[2] != 0) {
        cout << "No solution" << el;
        return;
    }
    int k = c / ans[2];
    int x = k * ans[0];
    int y = k * ans[1];
    cout << x << " " << y << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}