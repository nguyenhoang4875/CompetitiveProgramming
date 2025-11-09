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
    int n, m, tc = 0;
    while ((cin >> n >> m)) {
        vvi dist(n, vi(n, oo));
        for (int i = 0; i < n; ++i) dist[i][i] = 0;
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = dist[v][u] = min(dist[u][v], w);
        }

        // Floyd để lấy shortest path giữa mọi cặp
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        if (n == 3) {
            cout << "Case " << ++tc << ": " << 2 * (dist[0][1] + dist[1][2]) << "\n";
            continue;
        }

        int h = n - 2;
        int k = h / 2;
        int max_mask = (1LL << h) - 1;
        vector<int> hotel(h);
        for (int i = 0; i < h; ++i) hotel[i] = 1 + i;

        // f1[mask][u]: khoảng cách ngắng nhất đi từ HQ -> u, mask là những đỉnh chưa thăm
        // f2[mask][u]: khoảng cách ngắng nhất đi từ A -> u, mask là những đỉnh chưa thăm
        // 0: seen, 1: not seen
        vi f1((max_mask + 1) * n, oo), f2((max_mask + 1) * n, oo);

        // Base case: mask = 0 (all seen) → về 0 hoặc n-1 trực tiếp
        for (int i = 0; i < h; ++i) {
            int s = hotel[i];
            f1[0 * n + s] = dist[s][0];
            f2[0 * n + s] = dist[s][n - 1];
        }

        for (int mask = 1; mask <= max_mask; ++mask) {
            for (int i = 0; i < h; ++i) {
                if ((mask >> i) & 1) continue;  // did not seen i
                int s = hotel[i];
                int best1 = oo, best2 = oo;
                int mm = mask;
                while (mm) {
                    int p2 = LSOne(mm);
                    int j = __builtin_ctz(p2);
                    int u = hotel[j];
                    int new_mask = mask ^ p2;
                    best1 = min(best1, dist[s][u] + f1[new_mask * n + u]);
                    best2 = min(best2, dist[s][u] + f2[new_mask * n + u]);
                    mm -= p2;
                }
                f1[mask * n + s] = best1;
                f2[mask * n + s] = best2;
            }
        }

        int ans = oo;

        // Xét mọi tập S có size = k
        for (int S = 0; S <= max_mask; ++S) {
            if (__builtin_popcount(S) != k) continue;
            int T = max_mask ^ S;
            vector<int> idx;
            for (int i = 0; i < h; ++i)
                if (S & (1 << i)) idx.push_back(i);
            // thử mọi cặp (a,b) trong S
            for (int a : idx)
                for (int b : idx) {
                    int A = hotel[a], B = hotel[b];
                    int h2a = f2[T * n + A] + f1[(S ^ (1 << a)) * n + A];
                    int a2h = f2[(S ^ (1 << b)) * n + B] + f1[T * n + B];
                    ans = min(ans, h2a + a2h);
                }
        }

        cout << "Case " << ++tc << ": " << ans << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}