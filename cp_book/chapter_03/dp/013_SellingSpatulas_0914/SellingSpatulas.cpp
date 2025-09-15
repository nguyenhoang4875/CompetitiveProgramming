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
using pid = pair<int, double>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    while (true) {
        int n;
        cin >> n;
        if (!n) return;
        vector<pid> a(n);
        Rep(i, n) cin >> a[i].F >> a[i].S;

        double C = 0.08;

        double best = 0.0, sum = -oo;
        int l = 0, al = 0, r = 0, len = n + 1, pret = 0;
        for (auto& [m, p] : a) {
            double at_cur = p - C;
            sum += p - (m - pret) * C;
            if (at_cur >= sum) {
                l = m;
                sum = at_cur;
            }
            if (sum > best or (sum == best and m - l < len)) {
                best = sum;
                al = l;
                r = m;
                len = r - al;
            }
            pret = m;
        }
        cout << fixed << setprecision(2);
        if (best == 0.0) cout << "no profit" << el;
        else cout << best << " " << al << " " << r << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}