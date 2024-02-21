#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://oj.vnoi.info/problem/qbheap
 * Solution: Priority Queue
 *
 * TC: O(n log n)
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
const int ms = 2e5 + 5;
int n;
string cmd;

void solve() {
    priority_queue<int> q;
    while (cin >> cmd) {
        if (cmd[0] == '+') {
            if (q.size() < 15000) {
                cmd.erase(0, 1);
                q.push(stoll(cmd));
            }
        } else {
            if (!q.empty()) {
                int val = q.top();
                while (!q.empty() and q.top() == val) {
                    q.pop();
                }
            }
        }
    }
    vi ans;
    while (!q.empty()) {
        ans.pb(q.top());
        q.pop();
    }
    // ans.erase(unique(all(ans)), ans.end());
    ans.resize(unique(all(ans)) - ans.begin());  // okay
    cout << ans.size() << el;
    for (auto e : ans) {
        cout << e << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}