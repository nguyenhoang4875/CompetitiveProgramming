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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, x;
vii v;

int binarySearch(int pos, int val) {
    int l = pos, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid].F < val) {
            l = mid + 1;
        } else if (v[mid].F > val) {
            r = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

void solve() {
    cin >> n >> x;
    v = vii(n);
    For(i, 0, n - 1) {
        int x;
        cin >> x;
        v[i] = {x, i + 1};
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        while (l < r) {
            int val = x - v[i].F;
            int newVal = v[l].F + v[r].F;
            if (val == newVal) {
                if (l != i and r != i) {
                    cout << v[i].S << " " << v[l].S << " " << v[r].S << el;
                    return;
                }
            }
            if (newVal < val)
                l++;
            else
                r--;
        }
    }
    cout << "IMPOSSIBLE" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}