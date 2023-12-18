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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;

struct FenwickTree {
    int n;
    vi t;
    FenwickTree(int _n) {
        n = _n;
        t.resize(n + 1, 0);
    }
    void add(int i, int val) {
        while (i <= n) {
            t[i] += val;
            i += i & (-i);
        }
    }
    int get(int i) {
        int sum = 0;
        while (i > 0) {
            sum += t[i];
            i -= i & -i;
        }
        return sum;
    }
    int query(int l, int r) { return get(r) - get(l - 1); }

    void set(int i, int val) { add(i, val - query(i, i)); }
};

void solve() {
    int n = 8;
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    FenwickTree ft(n);
    For(i, 1, n) { ft.add(i, a[i]); }
    cout << ft.get(4) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}