#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using namespace std;

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
const int ms = 1e4 + 5;
int vmax = 1e6;
int n, x, y, z;
int a[ms];
vi evenNum;
vi oddNum;

int bfs(int s, int d) {
    vi dist(1e6 + 1, oo);
    queue<pii> q;
    q.push({a[s], 0});
    while (!q.empty()) {
        pii cp = q.front();
        q.pop();
        int val = cp.F;
        int cnt = cp.S;
        vi canGo;
        if (val & 1) {
            for (auto e : evenNum) {
                if (dist[e] == oo && (val % e == 0 || e % val == 0))
                    canGo.pb(e);
            }
        } else {
            for (auto e : oddNum) {
                if (dist[e] == oo && (val % e == 0 || e % val == 0))
                    canGo.pb(e);
            }
        }

        for (auto i : canGo) {
            dist[i] = cnt + 1;
            q.push({i, dist[i]});
        }
    }

    if (dist[a[d]] == oo) dist[a[d]] = -1;
    return dist[a[d]];
}

void solve() {
    cin >> n >> x >> y >> z;
    For(i, 1, n) cin >> a[i];

    For(i, 1, n) {
        if (a[i] & 1)
            oddNum.pb(a[i]);
        else
            evenNum.pb(a[i]);
    }
    // can optimize by run only one dfs from y
    int s1 = bfs(x, y);
    int s2 = bfs(y, z);

    if (s1 == -1 || s2 == -1) {
        cout << "-1\n";
        return;
    }
    cout << (s1 + s2) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}