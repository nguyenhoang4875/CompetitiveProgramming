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

struct FenwickTreeRangeUpdatePointQuery {
    int n;
    vector<int> tree;

    FenwickTreeRangeUpdatePointQuery(int _n) {
        n = _n;
        tree.resize(n + 1);
    }
    void add(int index, int val) {
        while (index <= n) {
            tree[index] += val;
            index += index & (-index);
        }
    }

    void updateRange(int l, int r, int val) {
        // Increase value at 'l' by 'val'
        add(l, val);

        // Decrease value at 'r+1' by 'val'
        add(r + 1, -val);
    }

    int get(int index) {
        int sum = 0;  // Initialize result

        while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }
};

void solve() {
    int n = 8;
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    FenwickTreeRangeUpdatePointQuery ft(n);
    For(i, 1, n) { ft.updateRange(i, i, a[i]); }
    cout << ft.get(4) << el;
    ft.updateRange(1, 4, 100);
    cout << ft.get(3) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}