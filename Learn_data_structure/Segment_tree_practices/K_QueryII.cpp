#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://oj.vnoi.info/problem/kquery2
 * Solution: Sqrt Decomposition + Fenwick Tree
 *
 * TC: O(q * sqrt(n) * log(10000) + sqrt(n))
 * MC: O(sqrt(n) * 1000)
 */

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
const int ms = 3e4 + 5, blockSize = 450;  // block size

int n, q;
int a[ms];
int tree[blockSize][10005];

void update(int block, int k, int val) {
    while (k > 0) {
        tree[block][k] += val;
        k -= k & -k;
    }
}

int sum(int block, int k) {
    int ans = 0;
    while (k <= 10000) {
        ans += tree[block][k];
        k += k & -k;
    }
    return ans;
}

void solve() {
    cin >> n;
    int block = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        block = i / blockSize;
        update(block, a[i], 1);
    }
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int i, v;
            cin >> i >> v;
            block = i / blockSize;
            update(block, a[i], -1);
            update(block, v, 1);
            a[i] = v;
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            int ans = 0;
            // count for l in middle block
            while (l <= r and l % blockSize != 0) ans += a[l++] > k;
            // cont for r in the middle block
            while (l <= r and r % blockSize != blockSize - 1) ans += a[r--] > k;

            // count for complete block
            if (l < r) {
                int bl = l / blockSize;
                int br = r / blockSize;
                for (int i = bl; i <= br; i++) {
                    ans += sum(i, k + 1);
                }
            }
            cout << ans << el;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}