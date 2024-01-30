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

int polyHash(string s) {
    int hash = 0;
    int pPower = 1;

    for (int i = 0; i < s.size(); i++) {
        hash += (s[i] - 'a' + 1) * pPower;
        pPower *= base;

        hash %= mod;
        pPower %= mod;
    }
    return hash;
}

void solve() {
    string text = "abaaaaaba";
    string pattern = "aba";

    int n = text.size(), m = pattern.size();

    int textHash = polyHash(text.substr(0, m));
    int patternHash = polyHash(pattern);

    int cnt = 0;
    if (textHash == patternHash) {
        cout << 0 << el;
        cnt++;
    }
    for (int i = 1; i + m <= n; i++) {
        textHash = (textHash - (text[i - 1] - 'a' + 1) + mod) % mod;
        textHash = textHash * inv(base, mod) % mod;
        textHash =
            (textHash + (text[i + m - 1] - 'a' + 1) * power(base, m - 1)) % mod;
        if (textHash == patternHash) {
            cout << i << el;
            cnt++;
        }
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}