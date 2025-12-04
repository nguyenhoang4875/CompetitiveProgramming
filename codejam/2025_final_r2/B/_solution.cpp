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

void solve() {
    int n, k;
    cin >> n >> k;
    vi s(n + 1);
    vi e(n + 1);

    For(i, 1, n) cin >> s[i];
    For(i, 1, n) cin >> e[i];
    vector<set<int>> add(k + 2);
    vector<set<int>> rm(k + 2);

    For(i, 1, n) {
        int l = s[i];
        add[l].insert(i);
        int r = e[i] + 1;
        if (r <= k) rm[r].insert(i);
    }

    set<int> cur;
    int cnt = 0;
    For(i, 1, k) {
        for (auto& e : add[i]) {
            cur.insert(e);
            bool bf = cur.count(e - 1);
            bool af = cur.count(e + 1);
            if (bf and af) --cnt;
            if (!bf and !af) ++cnt;
        }
        for (auto& e : rm[i])
            if (cur.count(e)) {
                bool bf = cur.count(e - 1);
                bool af = cur.count(e + 1);
                if (bf and af) ++cnt;
                if (!bf and !af) --cnt;
                cur.erase(e);
            }

        if (cur.size() == n) {
            cout << 1 << " ";
            continue;
        }

        if (cur.size() == 0) cnt = 0;
        cout << cnt << " ";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}