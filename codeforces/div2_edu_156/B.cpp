#include <bits/stdc++.h>
#define int long long

using namespace std;

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

void solve() {
    double px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;

    auto getDis = [&](double x1, double y1, double x2, double y2) -> double {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };
    // ko cat
    double ans = oo;
    double r1 = max(getDis(0, 0, ax, ay), getDis(px, py, ax, ay));
    double r2 = max(getDis(0, 0, bx, by), getDis(px, py, bx, by));
    ans = min(r1, r2);

    // cat
    double rr = getDis(ax, ay, bx, by) / 4;
    double r3 = max({rr, getDis(0, 0, ax, ay), getDis(px, py, bx, by)});
    double r4 = max({rr, getDis(px, py, ax, ay), getDis(0, 0, bx, by)});

    ans = min({ans, r3, r4});
    ans = sqrtl(ans);
    cout << fixed;
    cout.precision(8);
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}