#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/problemset/problem/1879/C
 * Solution: - find cnt for each length has same value.
 * 
 * TC: O(n)
 * MC: O(n)
 * 
*/

#define pb push_back
#define all(x) x.begin(), x.end()
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

const int oo = 1e18, mod = 998244353;
const int ms = 2e5 + 5;
int n;
string s;

vector<int> fac;

void initFac(int n) {
    fac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
}

void solve() {
    cin >> s;
    n = s.size();
    int cntWay = 1;
    int sumCnt = 0;
    For(i, 1, n - 1) {
        if(s[i - 1] == s[i]) {
            int cnt = 0;
            while(i <= n - 1 and s[i - 1] == s[i]) {
                cnt++;
                i++;
            }
            sumCnt += cnt;
            cntWay *= (cnt + 1);
            cntWay %= mod;
        }
    }
    cntWay = (cntWay) * fac[sumCnt] % mod;
    cout << sumCnt << " " << cntWay << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initFac(ms);
    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}