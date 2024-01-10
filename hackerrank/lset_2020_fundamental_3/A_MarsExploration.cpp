#include <bits/stdc++.h>
#define int long long
/**
 * Problem: https://www.hackerrank.com/contests/apptask-lset-2020-fundamentals-03/challenges
 */

using namespace std;

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
    string s;
    cin >> s;
    n = sz(s);
    int cnt = 0;
    For(i, 0, n - 1) {
        if (i % 3 == 1) {
            if (s[i] != 'O') cnt++;
        } else {
            if (s[i] != 'S') cnt++;
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