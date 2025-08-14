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
    vi a(30);
    a['B' - 'A'] = a['F' - 'A'] = a['P' - 'A'] = a['V' - 'A'] = 1;
    a['C' - 'A'] = a['G' - 'A'] = a['J' - 'A'] = a['K' - 'A'] = 2;
    a['Q' - 'A'] = a['S' - 'A'] = a['X' - 'A'] = a['Z' - 'A'] = 2;
    a['D' - 'A'] = a['T' - 'A'] = 3;
    a['L' - 'A'] = 4;
    a['M' - 'A'] = a['N' - 'A'] = 5;
    a['R' - 'A'] = 6;

    string s;
    while (cin >> s) {
        vi b;
        for (auto& e : s) {
            int v = e - 'A';
            if (b.empty() or b.back() != a[v]) b.pb(a[v]);
        }

        for (auto& e : b)
            if (e != 0) cout << e;
        cout << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}