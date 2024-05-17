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
int w, h, n, k, t;
vii v;

bool cmp(pii& p1, pii& p2) {
    if (p1.F == p2.F) {
        if (p1.F % 2) return p1.S > p2.S;
        return p1.S < p2.S;
    }
    return p1.F > p2.F;
}

int getDist(pii p) {
    int r = p.F;
    int c = p.S;
    int ans = (r - 1) * w;
    if (r % 2)
        ans += c - 1;
    else
        ans += w - c;
    return ans;
}

bool check(int val) {
    int cntPeople = 0;
    int i = 0;
    while (i < n) {
        int timeToMove = 2 * getDist(v[i]);
        int tm = val - timeToMove;
        int numItemTaken = tm / t;
        if (numItemTaken < 1) return false;
        i += numItemTaken;
        cntPeople++;
        if (cntPeople > k) return false;
    }
    return cntPeople <= k;
}

void solve() {
    cin >> w >> h >> n >> k >> t;
    v = vii(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F >> v[i].S;
    }
    sort(all(v), cmp);
    int l = 1, r = oo;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}