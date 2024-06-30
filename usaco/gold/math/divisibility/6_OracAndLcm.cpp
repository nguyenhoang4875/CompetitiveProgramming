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
const int MX = 1e5;
int n;

int a[ms];
map<int, vi> cntPrime;

void getPrimeFactors(int n) {
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        if (cnt) cntPrime[i].push_back(cnt);
    }
    if (n > 1) cntPrime[n].push_back(1);
}

int power(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) ans *= a;
        n /= 2;
        a *= a;
    }
    return ans;
}

void solve() {
    cin >> n;
    For(i, 1, n) {
        cin >> a[i];
        getPrimeFactors(a[i]);
    }

    int ans = 1;
    for (auto [f, s] : cntPrime) {
        int sn = s.size();
        sort(all(s));
        if (sn >= n - 1) {
            int val = sn == n ? s[1] : s[0];
            ans *= pow(f, val);
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