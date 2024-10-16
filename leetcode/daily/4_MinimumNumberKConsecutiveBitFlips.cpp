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
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

int minKBitFlips(vector<int>& a, int k) {
    int n = a.size();
    int curFlip = 0, ans = 0;
    vector<int> isFlipped(n);
    for (int i = 0; i < n; i++) {
        if (i >= k) {
            // if isFlipped[i - k] = 0 and curFlip at [i - 1] = 0 => curFlip = 0
            // if isFlipped[i - k] = 1 and curFlip at [i - 1] = 0 => curFlip = 1
            // if isFlipped[i - k] = 0 and curFlip at [i - 1] = 1 => curFlip = 1
            // if isFlipped[i - k] = 1 and curFlip at [i - 1] = 1 => curFlip = 0
            curFlip ^= isFlipped[i - k];
        }
        if (curFlip == a[i]) {
            // 0 == 0 or 1 == 1
            if (i + k - 1 >= n) return -1;
            curFlip ^= 1;
            isFlipped[i] = 1;
            ans++;
        }
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto& x : a) cin >> x;
    cout << minKBitFlips(a, k);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}