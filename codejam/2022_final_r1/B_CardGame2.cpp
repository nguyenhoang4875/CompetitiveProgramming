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
const int ms = 25;
int n, m, k;
int g[25];
bool used[25];
int a[ms], b[ms];
set<int> sa, sb;

void cal(set<int>& ss, int* t) {
    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += t[g[i]];
    }
    ss.insert(sum);
}
void genCom(int idx, int k, int n, set<int>& ss, int* t) {
    if (idx > k) {
        cal(ss, t);
        return;
    }
    for (int val = 1; val <= n; val++) {
        if (used[val]) continue;
        if (idx > 1 && g[idx - 1] > val) continue;
        used[val] = true;
        g[idx] = val;
        genCom(idx + 1, k, n, ss, t);
        used[val] = false;
    }
}

void solve() {
    sa.clear();
    sb.clear();
    cin >> n >> m >> k;
    For(i, 1, n) cin >> a[i];
    For(i, 1, m) cin >> b[i];
    memset(g, 0, sizeof(g));
    memset(used, 0, sizeof(used));
    genCom(1, k, n, sa, a);

    memset(g, 0, sizeof(g));
    memset(used, 0, sizeof(used));
    genCom(1, k, m, sb, b);

    int fa = *sa.begin();
    int fb = *sb.begin();
    int la = *sa.rbegin();
    int lb = *sb.rbegin();
    int maxVal = max(abs(fa - lb), abs(fb - la));

    int minVal = oo;
    for (auto l : sa) {
        auto up = sb.upper_bound(l);
        if (up != sb.end()) {
            minVal = min(minVal, abs(*up - l));
        }
        if (up != sb.begin()) {
            up--;
            minVal = min(minVal, abs(*up - l));
        }
        if (minVal == 0) break;
    }
    cout << minVal << " " << maxVal << el;
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