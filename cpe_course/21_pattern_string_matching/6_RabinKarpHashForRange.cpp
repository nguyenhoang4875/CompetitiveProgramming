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

const int oo = 1e18;
const int base = 31, mod = 1e9 + 7;
const int ms = 2e5 + 5;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a, res %= mod;
        b /= 2;
        a *= a;

        a %= mod;
    }
    return res;
}

int inv(int a, int b) { return power(a, b - 2); }

vector<int> prefixPolyHash(string s) {
    int hash = 0;
    int pPower = 1;
    int n = s.size();
    vector<int> ret(n);

    for (int i = 0; i < n; i++) {
        hash += (s[i] - 'a' + 1) * pPower;
        pPower *= base;

        hash %= mod;
        pPower %= mod;
        ret[i] = hash;
    }
    return ret;
}

int getHashRange(int l, int r, vector<int>& preSum) {
    if (l == 0) return preSum[r];
    return ((preSum[r] - preSum[l - 1] + mod) % mod) * inv(power(base, l), mod) % mod;
}

vector<string> getSubStringPalindrome(string s) {
    int n = s.size();
    string sRev = s;
    reverse(sRev.begin(), sRev.end());

    vector<int> ps = prefixPolyHash(s);
    vector<int> psRev = prefixPolyHash(sRev);
    vector<string> ans;
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            int h1 = getHashRange(l, r, ps);
            int h2 = getHashRange(n - 1 - r, n - 1 - l, psRev);
            if (h1 == h2) {
                ans.push_back(s.substr(l, r - l + 1));
            }
        }
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    vector<string> palindromes = getSubStringPalindrome(s);
    for (auto e : palindromes) {
        cout << e << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}