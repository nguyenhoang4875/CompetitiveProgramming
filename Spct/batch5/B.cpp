#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using namespace std;

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
int n, x;
int a[ms];
int ar[ms];
int preA[ms];
int preAr[ms];
int ans = oo;

int binarySearch(int idx, int val) {
    int pos = -1;
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (val + preAr[mid] >= x) {
            pos = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (val + preAr[pos] == x) return pos;
    return -1;
}

void solve() {
    cin >> n >> x;
    For(i, 1, n) {
        cin >> a[i];
        ar[i] = a[i];
    }
    reverse(ar + 1, ar + n + 1);
    For(i, 1, n) {
        preA[i] = preA[i - 1] + a[i];
        preAr[i] = preAr[i - 1] + ar[i];
    }
    ans = oo;
    For(i, 0, n) {
        int pos = binarySearch(i, preA[i]);
        if (pos == -1) continue;
        ans = min(ans, i + pos);
    }

    if (ans != oo)
        cout << ans << "\n";
    else
        cout << "-1\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}