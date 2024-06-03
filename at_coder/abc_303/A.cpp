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
int n;

void solve() {
    string s, t;
    cin >> n >> s >> t;
    if (s == t) {
        cout << "Yes" << el;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) continue;
        if ((s[i] == '1' and t[i] == 'l') or (s[i] == 'l' and t[i] == '1')) {
            continue;
        }
        if ((s[i] == '0' and t[i] == 'o') or (s[i] == 'o' and t[i] == '0')) {
            continue;
        }
        cout << "No" << el;
        return;
    }
    cout << "Yes" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}