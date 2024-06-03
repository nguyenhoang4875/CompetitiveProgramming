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
int n, d;
vvi graph;
vb seen;

int getDistance(pii p1, pii p2) {
    int len = ((p1.F - p2.F) * (p1.F - p2.F) + (p1.S - p2.S) * (p1.S - p2.S));
    return len;
}
void dfs(int cur, int par) {
    seen[cur] = true;
    for (auto x : graph[cur]) {
        if (x != par) {
            if (!seen[x]) dfs(x, cur);
        }
    }
}

void solve() {
    cin >> n >> d;
    vii v(n);
    for (auto &x : v) {
        cin >> x.F >> x.S;
    }

    seen = vb(n + 1, false);
    seen[0] = true;
    graph = vvi(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (getDistance(v[i], v[j]) <= d * d) {
                graph[i].pb(j);
                graph[j].pb(i);
            }
        }
    }
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        if (seen[i])
            cout << "Yes" << el;
        else
            cout << "No" << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}