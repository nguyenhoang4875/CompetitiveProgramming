#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Pattern String Matching
 * Solution: Brute forces
 *
 * TC: O(n * m)
 * MC: O(n * m)
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

void solve() {
    string s, pattern;
    cin >> s >> pattern;
    int n = s.size(), m = pattern.size();

    int cnt = 0;
    for (int i = 0; i + m <= n; i++) {
        if (s.substr(i, m) == pattern) {
            cout << i << el;
            cnt++;
        }
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}