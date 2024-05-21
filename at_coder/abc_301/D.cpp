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
int n, num;
string s;

void solve() {
    cin >> s;
    cin >> num;
    n = sz(s);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            int pos = n - i - 1;
            ans += 1LL << (n - 1 - i);
        }
    }

    if (ans > num) {
        cout << -1 << el;
        return;
    }

    for (int i = 0; i < n; i++) {
        int pos = n - i - 1;
        if (s[i] == '?' and ans + (1LL << (pos)) <= num) {
            ans += 1LL << pos;
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