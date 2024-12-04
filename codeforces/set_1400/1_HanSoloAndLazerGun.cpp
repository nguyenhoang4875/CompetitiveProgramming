#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
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
int n;

void solve() {
    cin >> n;
    int x0, y0;
    cin >> x0 >> y0;
    set<pii> st;
    For(i, 1, n) {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
    }

    n = st.size();
    map<pii, bool> seen;
    for (auto e : st) {
        seen[e] = false;
    }

    int cnt = 0;
    for (auto e : st) {
        if (!seen[e]) {
            seen[e] = true;
            cnt++;
            for (auto e2 : st) {
                if (e == e2) continue;
                bool sameLine = (e.F - x0) * (e2.S - y0) == (e.S - y0) * (e2.F - x0);
                if (sameLine) {
                    seen[e2] = true;
                }
            }
        }
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}