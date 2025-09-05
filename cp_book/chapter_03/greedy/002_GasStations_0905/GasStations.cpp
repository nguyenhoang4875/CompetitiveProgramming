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
    while (true) {
        int L, G;
        cin >> L >> G;
        if (!L and !G) return;

        vii a;
        Rep(i, G) {
            int x, r;
            cin >> x >> r;
            a.pb({x - r, x + r});
        }
        sort(all(a));

        int i = 0;
        int cur = 0;
        int cnt = 0;
        while (cur < L) {
            int best_i = -1;
            int max_r = -oo;
            int j = i;
            while (j < G and a[j].F <= cur) {
                if (max_r < a[j].S) {
                    max_r = a[j].S;
                    best_i = j;
                }
                j++;
            }
            if (best_i == -1) break;
            i = best_i + 1;
            cur = max_r;
            cnt++;
        }
        if (cur < L) cout << -1 << el;
        else cout << G - cnt << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}