#include <bits/stdc++.h>

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

const long long oo = 1e9, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int h, k;
    while (true) {
        cin >> h >> k;
        if (!h and !k) return;

        int n = 0;
        vi dn, best;
        dn.push_back(1);

        auto find_cur_max = [&](vi &dn) {
            vi f(1, 0);  // f[i]: số đồng tiền tiền cần dùng ít nhất để tạo được giá trị i

            int s = 1;
            while (true) {
                f.push_back(oo);
                for (auto &e : dn) {
                    if (s < e) break;
                    f[s] = min(f[s], f[s - e] + 1);
                }
                if (f[s] > h) break;  // h: số lượng đồng tiền tối đa
                ++s;
            }
            return s - 1;
        };

        function<void(int, vi &)> dfs = [&](int pos, vi &dn) {
            int cur_max = find_cur_max(dn);
            if (pos == k) {
                if (n < cur_max or (n == cur_max and dn < best)) {
                    n = cur_max;
                    best = dn;
                }
                return;
            }
            int next_last = dn.back() + 1;
            for (int val = next_last; val <= cur_max + 1; val++) {
                dn.push_back(val);
                dfs(pos + 1, dn);
                dn.pop_back();
            }
        };

        if (k == 1) {
            best = dn;
            n = find_cur_max(dn);
        } else dfs(1, dn);

        for (int d : best) {
            printf("%3d", d);
        }
        printf(" ->%3d\n", n);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}