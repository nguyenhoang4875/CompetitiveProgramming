#include <bits/stdc++.h>
#define int long long

/**
 * https://codeforces.com/contest/923/problem/B
 * priority queue with base
 */

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];
    vi t(n + 1);
    For(i, 1, n) cin >> t[i];
    int base = 0;
    priority_queue<int, vi, greater<int>> q;
    For(i, 1, n) {
        int sum = 0;
        q.push(a[i] + base);
        while (q.size() and (q.top() - base) <= t[i]) {
            sum += q.top() - base;
            q.pop();
        }
        sum += q.size() * t[i];
        base += t[i];
        cout << sum << " ";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}