#include <bits/stdc++.h>
#define int long long
/**
 * Problem: https://codejam.lge.com/problem/18766
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
    cin >> n;
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;
    For(i, 1, n) {
        string s;
        cin >> s;
        m1[s]++;
    }
    For(i, 1, n) {
        string s;
        cin >> s;
        m2[s]++;
    }
    bool cheat = false;
    for (auto e : m1) {
        if (m1[e.F] != m2[e.F]) {
            cheat = true;
            break;
        }
    }
    if (cheat) {
        cout << "CHEATER" << el;
    } else {
        cout << "NOT CHEATER" << el;
    }
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