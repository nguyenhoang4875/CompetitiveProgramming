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
    string s;
    while (getline(cin, s)) {
        vi a(60);
        for (auto &e : s) {
            if (('A' <= e and e <= 'Z') or ('a' <= e and e <= 'z')) {
                int v = 0;
                if (e < 'a') {
                    v = e - 'A';
                } else {
                    v = e - 'a' + 26;
                }
                a[v]++;
            }
        }
        int mx = *max_element(all(a));
        for (int i = 0; i < 52; i++) {
            if (a[i] == mx) {
                if (i >= 26) cout << char((i - 26) + 'a');
                else cout << char(i + 'A');
            }
        }
        cout << " " << mx << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}