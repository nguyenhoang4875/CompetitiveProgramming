#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
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

vector<int> min_prime(ms, 0);  // ms: max size
void minSieve(int n) {
    for (int i = 1; i <= n; i++) {
        min_prime[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (min_prime[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (min_prime[j] == j) {
                    min_prime[j] = i;
                }
            }
        }
    }
}

vector<int> getFactor(int number) {
    vector<int> f;
    while (number != 1) {
        f.push_back(min_prime[number]);
        number /= min_prime[number];
    }
    return f;
}

void solve() {
    int n;
    cin >> n;
    vi p(n + 1, 0);
    set<int> st;
    vvi f;
    int cnt = 0;
    map<int, int> hs;
    For(i, 1, n) {
        int x;
        cin >> x;
        if (min_prime[x] == x) {
            st.insert(x);
            cnt++;
            p[x]++;
        } else {
            vi tmp = getFactor(x);
            if (tmp.size() == 2) {
                f.push_back(tmp);
                hs[x]++;
            }
        }
    }
    int sn = sz(st);
    // case 1: prime number
    int ans = 0;
    int c1 = 0;
    for (auto &e : st) {
        c1 += (p[e]) * (cnt - p[e]);
    }
    c1 /= 2;
    ans += c1;

    // case 2: x = p * q: pair x, p and x, q
    int c2 = 0;
    for (auto e : f) {
        c2 += p[e[0]];
        if (e[0] != e[1]) c2 += p[e[1]];
    }
    ans += c2;

    // case 3: x = p * q: pair x, x
    int c3 = 0;
    for (auto &[f, s] : hs) {
        c3 += s + (s) * (s - 1) / 2;
    }
    ans += c3;
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mx = 2e5 + 5;
    minSieve(mx);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}