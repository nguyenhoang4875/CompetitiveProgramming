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
int n, p;
string s;

void solve() {
    cin >> s >> p;
    n = sz(s);
    vi a(27, 0);
    int sum = 0;
    For(i, 0, n - 1) {
        int val = s[i] - 'a' + 1;
        sum += val;
        a[val]++;
    }
    if (sum <= p) {
        cout << s << el;
        return;
    }
    vi cnt(27, 0);

    Ford(i, 26, 1) {
        while (sum > p and a[i] > 0) {
            sum -= i;
            a[i]--;
            cnt[i]++;
        }
        if (sum <= p) break;
    }
    For(i, 0, n - 1) {
        int val = s[i] - 'a' + 1;
        if (cnt[val] > 0) {
            cnt[val]--;
        } else {
            cout << s[i];
        }
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}