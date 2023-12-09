#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: ax % m = 1, find x in range [1, m - 1]
 * 
 * Solution: Using extended euclidean algorithms
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


vector<int> extendedGcd(int a, int b) {
    if (b == 0) {
        // return value of x and y
        return {1, 0, a};
    }
    vector<int> ans = extendedGcd(b, a % b);

    // after recursive call is over
    int xx = ans[0];
    int yy = ans[1];
    int gcd = ans[2];

    int x = yy;
    int y = xx - a / b * yy;
    return {x, y, gcd};
}

int modInverse(int a, int m) {
    vector<int> res = extendedGcd(a, m);
    int x = res[0];
    int gcd = res[2];
    if(gcd != 1) {
        // not relatively prime
        return -1;
    }
    return (x + m) % m;
}


void solve() {
    int a, m;
    cin >> a >> m;
    cout << modInverse(a, m) << el;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}