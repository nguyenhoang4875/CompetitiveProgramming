#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
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

void solve() {
    int n, m;
    cin >> n >> m;
    int l = 1;
    int ind[n + 2] = {0}, a[n + 1] = {0};
    ind[n + 1] = n + 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ind[x] = i;
        a[i] = x;
    }
    int c = 1;
    for (int i = 1; i <= n; i++) {
        if (l > ind[i]) c++;
        l = ind[i];
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        int r = a[x], s = a[y];
        swap(a[x], a[y]);
        if (ind[r - 1] <= ind[r] && ind[r - 1] > y) c++;
        if (ind[r - 1] > ind[r] && ind[r - 1] <= y) c--;
        if (ind[r] <= ind[r + 1] && y > ind[r + 1]) c++;
        if (ind[r] > ind[r + 1] && y <= ind[r + 1]) c--;
        ind[r] = y;
        if (ind[s - 1] <= ind[s] && ind[s - 1] > x) c++;
        if (ind[s - 1] > ind[s] && ind[s - 1] <= x) c--;
        if (ind[s] <= ind[s + 1] && x > ind[s + 1]) c++;
        if (ind[s] > ind[s + 1] && x <= ind[s + 1]) c--;
        ind[s] = x;
        cout << c << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}