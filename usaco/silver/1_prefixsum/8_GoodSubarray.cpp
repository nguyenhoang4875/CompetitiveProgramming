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
int n;
vi a;
char tmp;

void solve() {
    cin >> n;
    a = vi(n);
    For(i, 0, n - 1) {
        cin >> tmp;
        a[i] = tmp - '0';
    }

    map<int, int> mapFreq;
    mapFreq[0] = 1;
    int sum = 0;
    int ans = 0;
    int x;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        x = sum - i - 1;
        if (!mapFreq.count(x)) {
            mapFreq[x] = 0;
        }
        mapFreq[x]++;
        ans += mapFreq[x] - 1;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}