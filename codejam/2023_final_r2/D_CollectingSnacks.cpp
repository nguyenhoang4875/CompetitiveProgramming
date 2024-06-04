#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1000003;
const int ms = 2e6;
int r, c, n;

vector<int> fac;

void initFac(int n) {
    fac.resize(n + 5);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
}

int power(int a, int n) {
    int ans = 1;
    a = a % mod;
    while (n > 0) {
        if (n & 1) ans = (ans * a) % mod;
        n /= 2;
        a = (a * a) % mod;
    }
    return ans;
}

int nCr(int n, int k) {
    int ans = fac[n];
    ans = ans * power(fac[k], mod - 2) % mod;
    ans = ans * power(fac[n - k], mod - 2) % mod;
    return ans;
}

void solve() {
    cin >> r >> c >> n;
    vii cookies(n);
    for (int i = 0; i < n; i++) {
        cin >> cookies[i].F >> cookies[i].S;
    }
    sort(all(cookies));
    cookies.push_back({r, c});

    map<pii, int> maxCountMap;
    map<pii, int> pathCountMap;
    vii checkedCookies;

    maxCountMap[{1, 1}] = 0;
    pathCountMap[{1, 1}] = 1;
    checkedCookies.push_back({1, 1});

    for (auto cookie : cookies) {
        int row = cookie.F;
        int col = cookie.S;
        int maxCnt = -1;
        vii maxCookies;

        for (auto e : checkedCookies) {
            int curCnt = 0;
            if (e.S <= col) {
                curCnt = maxCountMap[e] + 1;
                if (maxCnt < curCnt) {
                    maxCnt = curCnt;
                    maxCookies.clear();
                    maxCookies.pb(e);
                } else if (maxCnt == curCnt) {
                    maxCookies.pb(e);
                }
            }
        }

        maxCountMap[cookie] = maxCnt;
        checkedCookies.push_back(cookie);
        int curCnt = 0;
        for (auto maxCookie : maxCookies) {
            int rowMax = maxCookie.F;
            int colMax = maxCookie.S;
            int height = row - rowMax;
            int width = col - colMax;
            curCnt = (curCnt + nCr(width + height, width) * pathCountMap[{rowMax, colMax}]) % mod;
        }
        pathCountMap[{row, col}] = curCnt;
    }
    cout << pathCountMap[{r, c}] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    initFac(ms);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}