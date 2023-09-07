#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Hamiltonian Path is a path in directed or undirected graph
 * that visit each vertex exactly once.
 * Input: n vertex, m edge and edges represent by a to b
 * Ouput: can construct hamiltonian path or not
 *
 * Solution: Recursion + Memo
 *
 * TC: O(n * n * 2^n)
 * MC: O(2^n * n)
 *
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

const int MS = 10;
int n, m;
vector<int> g[MS];
map<pair<int, set<int>>, bool> mp;

bool dp(int cur, set<int> st) {
    // base case
    if (st.size() == n) return true;
    if (mp.count({cur, st})) return mp[{cur, st}];

    bool ans = false;
    for (auto x : g[cur]) {
        if (!st.count(x)) {
            set<int> temp = st;
            temp.insert(x);
            ans |= dp(x, temp);
        }
    }

    return mp[{cur, st}] = ans;
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bool ans = false;

    for (int i = 0; i < n; i++) {
        set<int> st;
        st.insert(i);
        ans |= dp(i, st);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}