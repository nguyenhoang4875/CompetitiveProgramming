#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using piv = pair<int, vector<int>>;

//*** START CODING ***//

int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 4e3 + 5;
int v[ms];
int n, m;
string x;

void solve() {
    cin >> n >> x;
    m = x.size();
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    m--;
    int maxMask = (1LL << m) - 1;
    vector<pii> a;
    vector<pair<int, string>> b;
    for (int mask = 0; mask <= maxMask; mask++) {
        vector<int> vs;
        int sum = 0;
        string tmp = "";
        // tmp += x[0];
        int tm = 0;  // reverseMask
        int cur = 0;
        for (int i = 0; i < m; i++) {
            if (getBit(mask, i)) {
                tm += 1LL << (m - 1 - i);
                for (int l = cur; l <= i; l++) {
                    tmp += x[l];
                }
                cur = i + 1;
                sum += stoll(tmp);
                tmp = "";
            }
        }
        if (cur <= m) {
            for (int l = cur; l <= m; l++) {
                tmp += x[l];
            }
            sum += stoll(tmp);
        }
        a.push_back({sum, tm});
    }

    sort(all(a), [&](pii p1, pii p2) {
        if (p1.F == p2.F) {
            return p1.S > p2.S;
        }
        return p1.F < p2.F;
    });

    int ws = 0, wp = 0;
    for (int i = 1; i <= n; i++) {
        int pos = v[i] - 1;
        ws += a[pos].F;
        wp += (__builtin_popcount(a[pos].S));
    }
    cout << ws << " " << wp << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}