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
int q, n, m;

void solve() {
    cin >> q >> n >> m;
    vi a(n);  // fields
    for (auto &x : a) cin >> x;

    vi b(m);  // strips
    for (auto &x : b) cin >> x;

    int sum = 0;  // sum fieds;
    for (auto e : a) {
        sum += e;
    }

    int ans = 0;
    if (q > sum) {
        sort(all(b), greater<int>());
        int numStrip = 0;
        for (auto e : b) {
            numStrip++;
            if (sum + e < q) {
                sum += e;
            } else break;
        }
        ans = q - numStrip;
    } else if (q < sum) {
        bitset<150005> f(0);
        // vi f(q + 1, 0); // f[i] that can form sum of fileds equal to q;
        f[0] = 1;
        for(auto e: a) {
            f |= (f << e);
        }
        ans = q - !f[q];
    } else {
        ans = q;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}