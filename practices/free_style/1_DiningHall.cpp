#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/contest/2090/problem/C
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

struct pos {
    int x, y, dist, tx, ty;

    bool operator<(const pos& p) const {
        if (dist == p.dist) {
            if (x == p.x) return y < p.y;
            return x < p.x;
        }
        return dist < p.dist;
    }
};
struct table {
    int x, y;
    bool operator<(const table& t) const {
        if (x + y == t.x + t.y) { return x < t.x; }
        return x + y < t.x + t.y;
    }
};

void solve() {
    int n;
    cin >> n;
    vi a(n);
    Rep(i, n) cin >> a[i];
    int sq = sqrtl(n + 5);
    sq *= 2;

    set<table> st;
    for (int i = 0; i < sq; i++) {
        for (int j = 0; j < sq; j++) { st.insert({3 * i + 1, 3 * j + 1}); }
    }

    set<pos> sp;
    for (int x = 0; x <= sq; x++) {
        for (int y = 0; y <= sq; y++) {
            sp.insert({3 * x + 1, 3 * y + 1, 3 * x + 1 + 3 * y + 1, 3 * x + 1, 3 * y + 1});
            sp.insert({3 * x + 2, 3 * y + 1, 3 * x + 2 + 3 * y + 1, 3 * x + 1, 3 * y + 1});
            sp.insert({3 * x + 1, 3 * y + 2, 3 * x + 1 + 3 * y + 2, 3 * x + 1, 3 * y + 1});
            sp.insert({3 * x + 2, 3 * y + 2, 3 * x + 2 + 3 * y + 2 + 2, 3 * x + 1, 3 * y + 1});
        }
    }
    Rep(i, n) {
        if (a[i] == 1) {
            auto it = sp.begin();
            int px = it->x;
            int py = it->y;
            int tx = it->tx;
            int ty = it->ty;
            cout << px << " " << py << el;
            sp.erase(it);
            st.erase({tx, ty});
        } else {
            auto it = st.begin();
            int tx = it->x;
            int ty = it->y;
            cout << tx << " " << ty << el;
            st.erase(it);
            sp.erase({tx, ty, tx + ty, tx, ty});
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}