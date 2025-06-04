#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
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
int a[ms];

struct node {
    int a, b, c;

    bool operator<(const node& n) const {
        if (a == n.a) {
            if (b == n.b) {
                return c < n.c;
            }
            return b < n.b;
        }
        return a < n.a;
    }

    bool operator==(const node& n) const { return a == n.a && b == n.b && c == n.c; }

    friend ostream& operator<<(ostream& os, const node& n) {
        return os << n.a << " " << n.b << " " << n.c;
    }
};

int nC2(int n) { return n * (n - 1) / 2; }

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    vector<node> v;
    for (int i = 1; i <= n - 2; i++) {
        v.pb({a[i], a[i + 1], a[i + 2]});
    }

    map<vi, int> m;
    map<vi, int> m1;
    map<vi, int> m2;
    map<vi, int> m3;

    for (auto e : v) {
        m1[{e.a, e.b}]++;
        m2[{e.a, e.c}]++;
        m3[{e.b, e.c}]++;
        m[{e.a, e.b, e.c}]++;
    }

    auto cal = [&](map<vi, int>& m) {
        int ret = 0;
        for (auto e : m) ret += nC2(e.S);
        return ret;
    };

    int ans = 0;
    ans += cal(m1);
    ans += cal(m2);
    ans += cal(m3);
    ans -= 3 * cal(m);

    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}