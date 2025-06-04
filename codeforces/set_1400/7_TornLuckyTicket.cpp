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
    vector<vector<string>> v(10);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v[s.size()].pb(s);
    }

    int ans = 0;
    For(x, 1, 5) {
        For(y, 1, 5) {
            if ((x + y) % 2 == 1) continue;
            int mid = (x + y) / 2;
            vi cnt(201, 0);
            for (auto s : v[x]) {
                int t = 100;
                for (int i = 0; i < x; i++) {
                    if (i < mid)
                        t += s[i] - '0';
                    else
                        t -= s[i] - '0';
                }
                cnt[t]++;
            }
            for (auto s : v[y]) {
                int t = 100;
                for (int i = 0; i < y; i++) {
                    if (i + x >= mid)
                        t += s[i] - '0';
                    else
                        t -= s[i] - '0';
                }
                ans += cnt[t];
            }
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}