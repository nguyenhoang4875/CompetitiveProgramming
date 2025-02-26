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

int powerMod(int a, int n) {
    int ans = 1;
    a = a % mod;
    while (n > 0) {
        if (n & 1) ans = (ans * a) % mod;
        n /= 2;
        a = (a * a) % mod;
    }
    return ans;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vi a(n);

    int sum = 0;
    for (auto& e : a) {
        cin >> e;
        sum += e;
    }

    map<int, int> cnt;
    for (auto e : a) {
        cnt[sum - e]++;
    }

    int cur = sum - a[n - 1];
    while (cnt[cur] % x == 0) {
        cnt[cur + 1] += cnt[cur] / x;
        cnt[cur] = 0;
        cur++;
    }
    cur = min(cur, sum);  // cur can not greater than sum
    cout << powerMod(x, cur) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}