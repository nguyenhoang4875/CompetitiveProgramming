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
vii vp;

struct rect {
    int minX, maxX, minY, maxY;
    friend ostream& operator<<(ostream& os, const rect& rt) {
        return os << rt.minX << " " << rt.maxX << " " << rt.minY << " " << rt.maxY;
    }
};

int calArea(rect rt) { return (rt.maxX - rt.minX) * (rt.maxY - rt.minY); }

int sol(vii& vp) {
    vector<rect> ps1(n);
    int minX = vp[0].F, maxX = vp[0].F, minY = vp[0].S, maxY = vp[0].S;
    ps1[0] = {minX, maxX, minY, maxY};

    For(i, 1, n - 1) {
        rect rt = ps1[i - 1];
        int x = vp[i].F;
        int y = vp[i].S;
        minX = min(x, rt.minX);
        maxX = max(x, rt.maxX);
        minY = min(y, rt.minY);
        maxY = max(y, rt.maxY);
        ps1[i] = {minX, maxX, minY, maxY};
    }

    vector<rect> ps2(n);
    minX = vp[n - 1].F, maxX = vp[n - 1].F, minY = vp[n - 1].S, maxY = vp[n - 1].S;
    ps2[n - 1] = {minX, maxX, minY, maxY};

    Ford(i, n - 2, 0) {
        rect rt = ps2[i + 1];
        int x = vp[i].F;
        int y = vp[i].S;
        minX = min(x, rt.minX);
        maxX = max(x, rt.maxX);
        minY = min(y, rt.minY);
        maxY = max(y, rt.maxY);
        ps2[i] = {minX, maxX, minY, maxY};
    }

    int originArea = calArea(ps1[n - 1]);

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = calArea(ps1[i]);
        sum += calArea(ps2[i + 1]);
        ans = max(ans, originArea - sum);
    }

    return ans;
}

void solve() {
    cin >> n;
    vp = vii(n);
    vii vp2(n);
    For(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        vp[i] = {x, y};
        vp2[i] = {y, x};
    }
    sort(all(vp));
    sort(all(vp2));
    int ans = sol(vp);
    ans = max(ans, sol(vp2));
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}