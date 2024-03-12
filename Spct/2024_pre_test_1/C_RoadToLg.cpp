#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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
const int ms = 2e5 + 5;
int n, t;
int sr, sc;
vii v, v2;
map<pii, vii> mCanGo;

bool canGo(int x1, int y1, int x2, int y2) {
    int dist = abs(x1 - x2) + abs(y1 - y2);
    return dist <= t;
}
void preCal() {
    int ss = sz(v2);
    for (int i = 0; i < ss; i++) {
        for (int j = i + 1; j < ss; j++) {
            if (canGo(v2[i].F, v2[i].S, v2[j].F, v2[j].S)) {
                mCanGo[{v2[i].F, v2[i].S}].pb({v2[j].F, v2[j].S});
                mCanGo[{v2[j].F, v2[j].S}].pb({v2[i].F, v2[i].S});
            }
        }
    }
}

void solve() {
    cin >> n >> t;
    cin >> sr >> sc;
    v = vii(n);
    map<pii, int> dist;
    v2 = vii();
    For(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
        dist[{x, y}] = oo;
    }
    v.push_back({sr, sc});
    v2 = v;
    v2.pb({0, 0});
    preCal();

    dist[{sr, sc}] = oo;
    queue<pii> q;
    q.push({0, 0});
    dist[{0, 0}] = 0;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (auto e : mCanGo[{cur.F, cur.S}]) {
            if (dist[{e.F, e.S}] != oo) continue;
            dist[{e.F, e.S}] = dist[{cur.F, cur.S}] + 1;
            q.push({e.F, e.S});
        }
    }
    if (dist[{sr, sc}] == oo)
        cout << -1 << el;
    else
        cout << dist[{sr, sc}] - 1 << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}