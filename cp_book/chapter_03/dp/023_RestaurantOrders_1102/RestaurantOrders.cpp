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
    int n;
    cin >> n;
    vi c(n + 1);
    For(i, 1, n) cin >> c[i];

    int m;
    cin >> m;
    vi orders(m);
    Rep(i, m) cin >> orders[i];
    int mx = *max_element(all(orders));

    const int UNR = -1, ABM = -2;
    vi f(mx + 1, UNR);  // the index of cost: for last selected item with total cost = s
    f[0] = 0;
    For(i, 1, n) {
        int cost = c[i];
        for (int s = 0; s + cost <= mx; ++s) {  // can select c[i] multiple times
            int t = s + cost;
            if (f[s] == ABM) {
                f[t] = ABM;
            } else if (f[s] != UNR) {
                if (f[t] == UNR) {
                    f[t] = i;
                } else {
                    f[t] = ABM;
                }
            }
        }
    }

    for (auto s : orders) {
        if (f[s] == UNR) cout << "Impossible" << el;
        else if (f[s] == ABM) cout << "Ambiguous" << el;
        else {
            vi ans;
            while (s) {
                ans.pb(f[s]);
                s -= c[f[s]];
            }
            sort(all(ans));
            for (auto& e : ans) cout << e << " ";
            cout << el;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}