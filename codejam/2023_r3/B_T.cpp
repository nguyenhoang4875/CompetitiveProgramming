#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define trace(...) debug(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void debug(const char* name, Arg1&& arg1) {
    cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void debug(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " | ";
    debug(comma + 1, args...);
}
#define ordered_set                              \
    tree<int, null_type, less<int>, rb_tree_tag, \
         tree_order_statistics_node_update>

const int INF = 1000000000 + 5;
const int N = 2e5 + 5;
const int M = 1e6 + 5;
const ll oo = 1ll << 60;
const int mod = 998244353;

ll f, w, l, n;

struct Point {
    ll x, y, z;
    Point(){};
    Point(ll x, ll y, ll z) : x(x), y(y), z(z){};
};

vector<Point> a;

ll crossFloor(ll a, ll b) {
    if (a < b)
        return 2 * (b - a);
    else
        return a - b;
}

ll getTime(Point a, Point b) {
    if (a.z == b.z) {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }
    ll edgeX[] = {1, 1, w, w};
    ll edgeY[] = {1, l, 1, l};

    ll ret = oo;

    for (int i = 0; i < 4; ++i) {
        ll aToEdge = abs(a.x - edgeX[i]) + abs(a.y - edgeY[i]);
        ll bToEdge = abs(b.x - edgeX[i]) + abs(b.y - edgeY[i]);
        ret = min(ret, aToEdge + crossFloor(a.z, b.z) + bToEdge);
    }
    return ret;
}

void solve() {
    cin >> f >> w >> l >> n;
    ++n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].z >> a[i].x >> a[i].y;
    }
    vector<vector<ll>> dp((1 << n), vector<ll>(n, oo));
    dp[1][0] = 0;
    for (int mask = 2; mask < (1 << n); ++mask) {
        /*
        n = 4
        mask = 1 -> 0001
        dp[state mask][last]

        0001
        3210

        1 -> 0001

        0001 visted point

        dp[0001][0] = 0 --- visited 0001 hien tai -> 0 va a mat 0s

        cur 1->n-1 --- 1 -> 3

        dp[0010][1] = INF

        dp[0001][0]
        xphat tu 0 -> i
        -> dp[0011][1]
        -> dp[0101][2]
        -> dp[1001][3]

        cur -> 1->n-1 --- 1 -> 3
        -> dp[0011][1] <- dp[0001][0] + time(0->1) from = 0
        dp[0001][0] = 0

        cur <- from
        xxxx ko chua cur
        dp[xxxxx][cur] <- dp[xxxy][from] + time(from,cur)

        cur -> multi from

        min from

        dp[mask][cur] = max(dp[prevMask][from] + time(from, cur))

        0010 -> 1111

        (mask >> from) & 1
        -> check trong mask index from == 1

        0000001 & 1 ->

        001111011000
        000010000000

        dp[001111011000][cur] = min(dp[001101011000][from] + time(from,cur))

        dp[0010][1] = oo
        dp[0001][0] = 0
        */

        for (int cur = 1; cur < n; ++cur) {
            if ((mask >> cur) & 1) {
                for (int from = 0; from < n; ++from) {
                    if ((mask >> from) & 1 && from != cur &&
                        dp[mask ^ (1 << cur)][from] != oo) {
                        dp[mask][cur] =
                            min(dp[mask][cur], dp[mask ^ (1 << cur)][from] +
                                                   getTime(a[from], a[cur]));
                    }
                }
            }
        }
    }
    ll ret = oo;
    for (int i = 1; i < n; ++i) {
        ret = min(ret, dp[(1 << n) - 1][i]);
    }
    cout << ret << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}