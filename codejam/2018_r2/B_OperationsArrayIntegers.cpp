#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/15932
 * Solution: tracking back for each index
 * 
 * TC: O(m * q)
 * MC: O(m * q)
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

struct operation {
    char cmd;
    int s, e;
};

int n, q, m;
vector<operation> v;

int reverseTracking(int pos) {
    int val = 0;
    for (auto op : v) {
        if (op.cmd == 'a') {
            val += pos;
        } else {
            if (op.s <= pos and pos <= op.e) {
                // in segment: reverse the position
                pos = (op.s + op.e) - pos;
            }
        }
    }
    return val;
}

void solve() {
    v.clear();
    cin >> n >> q >> m;

    for (int i = 0; i < q; i++) {
        char cmd;
        int s, e;
        cin >> cmd;
        if (cmd == 'a') {
            v.pb({cmd});
        } else {
            cin >> s >> e;
            v.pb({cmd, s, e});
        }
    }

    reverse(all(v)); // reverse operations for tracking back

    int x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << reverseTracking(x) << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}