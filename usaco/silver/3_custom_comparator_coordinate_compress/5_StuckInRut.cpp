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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

struct node {
    int x, y, id;

    friend ostream &operator<<(ostream &os, const node &n) {
        return os << n.x << " " << n.y << " " << n.id;
    }
};
vector<node> vx, vy;

void solve() {
    cin >> n;
    For(i, 1, n) {
        char type;
        int x, y;
        cin >> type;
        cin >> x >> y;
        if (type == 'N')
            vy.push_back({x, y, i});
        else
            vx.push_back({x, y, i});
    }
    sort(all(vy), [&](node v1, node v2) {
        if (v1.x == v2.x) return v1.y < v2.y;
        return v1.x < v2.x;
    });
    sort(all(vx), [&](node v1, node v2) {
        if (v1.y == v2.y) return v1.x < v2.x;
        return v1.y < v2.y;
    });

    vi stopped(n + 1, false);
    vi dist(n + 1, 0);

    for (auto c1 : vx) {
        for (auto c2 : vy) {
            if (stopped[c1.id] or stopped[c2.id]) continue;
            if (c1.y >= c2.y and c1.x <= c2.x) {
                int lenX = c2.x - c1.x;
                int lenY = c1.y - c2.y;
                if (lenX > lenY) {
                    stopped[c1.id] = true;
                    dist[c2.id] += dist[c1.id] + 1;
                } else if (lenX < lenY) {
                    stopped[c2.id] = true;
                    dist[c1.id] += dist[c2.id] + 1;
                }
            }
        }
    }
    For(i, 1, n) cout << dist[i] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}