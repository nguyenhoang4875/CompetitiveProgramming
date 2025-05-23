#include <bits/stdc++.h>
#define int long long

using namespace std;
/*
Given a target array ( a ) and an initial array of all zeros,
where you can pick any segment  ([l,r]) and add any positive integer ( x ) to all elements in
([l,r]), find the minimum number of operations needed to reach ( a ).

Solution:
We want to cover the "histogram" defined by ( a ) with as few horizontal rectangles as possible.

Solution Idea (Monotonic Stack Approach):
- Traverse (a) from left to right.
- Maintain a monotonically increasing stack of previous heights.
- At each position (i):
- If the current height (a[i]) is less than the previous, pop until the stack is valid.
- If the current height (a[i]) is greater than the previous, push it onto the stack and increment
the answer.

 */

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
    vi a(n);
    Rep(i, n) cin >> a[i];

    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() and st.top() > a[i]) st.pop();
        if (st.empty() or st.top() < a[i]) {
            if (a[i] > 0) {
                st.push(a[i]);
                ans++;
            }
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}