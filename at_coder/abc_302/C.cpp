#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m;

void solve() {
    cin >> n >> m;
    vector<string> vs(n);
    For(i, 0, n - 1) cin >> vs[i];
    vi p(n);
    iota(all(p), 0);

    do {
        vector<string> sp(n);
        for (int i = 0; i < n; i++) {
            sp[i] = vs[p[i]];
        }

        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            string s1 = sp[i], s2 = sp[i + 1];
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (s1[j] != s2[j]) cnt++;
            }
            if (cnt != 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << el;
            return;
        }

    } while (next_permutation(all(p)));

    cout << "No" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}