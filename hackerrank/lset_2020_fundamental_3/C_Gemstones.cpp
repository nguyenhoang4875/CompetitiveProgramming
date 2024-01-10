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
const int ms = 1e5 + 5;
int n;

void solve() {
    cin >> n;
    vector<string> vs;
    For(i, 1, n) {
        string s;
        cin >> s;
        vs.pb(s);
    }

    int cnt = 0;
    For(i, 0, 25) {
        char c = char(i + 'a');
        bool found = false;
        for (auto s : vs) {
            found = false;
            for (auto e : s) {
                if (e == c) {
                    found = true;
                    continue;
                }
            }
            if (!found) break;
        }
        if (found) cnt++;
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}