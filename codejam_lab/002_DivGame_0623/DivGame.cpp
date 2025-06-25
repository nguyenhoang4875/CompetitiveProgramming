#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
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
    int n;
    cin >> n;

    int p = 2;
    map<int, int> cnt;
    int sq = sqrtl(n) + 1;
    while (p <= sq) {
        int num = 0;
        while (n % p == 0) {
            num++;
            n /= p;
        }
        cnt[p] = num;
        sq = sqrtl(n) + 1;
        p++;
    }
    if (n != 1) cnt[n]++;
    int ans = 0;
    for (auto &[f, s] : cnt) {
        int i = 1;
        while (s >= i) {
            ans++;
            s -= i;
            i++;
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