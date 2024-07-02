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
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
int a[ms];

void solve() {
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        a[i + 1] = s[i] - '0';
    }
    int sum = 0;
    map<int, int> cnt;
    int ans = 0;
    cnt[0] = 1;
    int p10 = 1;
    // abcd % m = (a * 10^3 + b * 10^2 + c *10^1 + d) % m
    for (int i = n; i >= 1; i--) {
        sum += a[i] * p10;
        sum %= 2019;
        ans += cnt[sum];
        cnt[sum]++;
        p10 = p10 * 10 % 2019;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}