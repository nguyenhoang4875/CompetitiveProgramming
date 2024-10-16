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
int r1, c1, r2, c2;
string s;

void solve() {
    cin >> r1 >> c1 >> r2 >> c2;
    cin >> n;
    cin >> s;
    vi cnt(5, 0);
    for (auto e : s) {
        if (e == 'L') cnt[1]++;
        if (e == 'R') cnt[2]++;
        if (e == 'D') cnt[3]++;
        if (e == 'U') cnt[4]++;
    }

    auto check = [&](int k) {
        int curR = r1, curC = c1;
        int t = k / n;
        curR -= cnt[1] * t;
        curR += cnt[2] * t;
        curC -= cnt[3] * t;
        curC += cnt[4] * t;
        int rm = k - n * t;
        for (int i = 0; i < rm; i++) {
            if (s[i] == 'L') curR--;
            if (s[i] == 'R') curR++;
            if (s[i] == 'D') curC--;
            if (s[i] == 'U') curC++;
        }

        int dist = abs(r2 - curR) + abs(c2 - curC);
        return k >= dist;
    };

    int ans = -1;
    int l = 0, r = oo;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}