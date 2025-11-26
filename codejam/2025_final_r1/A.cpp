#include<bits/stdc++.h>
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
    int n, m;
    cin >> n >> m;
    vi d(n);
    Rep(i, n) cin >> d[i];
    vi c(m);
    Rep(i, m) cin >> c[i];

    map<int, int> cnt;
    for(auto& e: d) cnt[e]++;
    priority_queue<pii> q;
    for(auto &[f, s]: cnt) {
        q.push({f, s});
    }

    Rep(i, m) {
        int base = c[i] - i;
        int res = 0;
        int num = 0;
        while(q.size() and q.top().F > base) {
            auto [f, s] = q.top();
            q.pop();
            res += f * s;
            num += s;
        }
        res -= num * base;
        q.push({base, num});
        cout << res << el;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}