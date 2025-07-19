#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
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

const long long oo = 1e12, mod = 1e9 + 7;
const int ms = 2e5 + 5;

vi l, l1;
void init() {
    vi a = {4, 7};
    function<void(int)> genLucky = [&](int x) {
        if (x > oo) return;
        if (x != 0) l.push_back(x);
        Rep(i, 2) { genLucky(x * 10 + a[i]); }
    };
    genLucky(0);
    sort(all(l));

    int n = l.size();

    function<void(int, int)> genVeryLucky = [&](int x, int pos) {
        if (x > oo) return;
        if (x != 1) l1.push_back(x);
        for (int i = pos; i < n; i++) {
            if (x > oo / l[i]) break;
            genVeryLucky(x * l[i], i);
        }
    };
    genVeryLucky(1LL, 0);
    sort(all(l1));
    l1.erase(unique(all(l1)), l1.end());
}

int solve() {
    int a, b;
    cin >> a >> b;

    auto low = lower_bound(all(l1), a);
    auto up = upper_bound(all(l1), b);
    return up - low;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int tcs = 1;
    cin >> tcs;
    For(i, 1, tcs) { cout << "Case " << i << ": " << solve() << el; }
    return 0;
}