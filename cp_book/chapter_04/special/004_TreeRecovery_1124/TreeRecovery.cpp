#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

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

int n;

void solve() {
    string pre, in, post;
    while (cin >> pre >> in) {
        post.clear();
        n = pre.size();
        map<char, int> in_idx;  // get index of char inside in faster
        Rep(i, n) in_idx[in[i]] = i;

        function<void(int, int, int)> dfs = [&](int in_start, int in_end, int pre_idx) {
            if (in_start >= in_end) return;
            char root = pre[pre_idx];
            int pos = in_idx[root];
            int left_len = pos - in_start;  // left side | root | right size inside in order

            dfs(in_start, in_start + left_len, pre_idx + 1);
            dfs(pos + 1, in_end, pre_idx + left_len + 1);
            post.pb(root);
        };
        dfs(0, n, 0);
        cout << post << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}