#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m, q;

vector<vector<int>> getDivsTillN(int n) {
    vector<vector<int>> ans = vector<vector<int>>(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            ans[j].push_back(i);
        }
    }
    return ans;
}

void solve() {
    cin >> n >> m >> q;
    vi a(n + 1);
    vi b(m + 1);
    For(i, 1, n) cin >> a[i];
    For(i, 1, m) cin >> b[i];

    vvi ds = getDivsTillN(ms);

    int sumA = 0, sumB = 0;
    For(i, 1, n) sumA += a[i];
    For(i, 1, m) sumB += b[i];

    set<int> sa, sb;
    For(i, 1, n) sa.insert(sumA - a[i]);
    For(i, 1, m) sb.insert(sumB - b[i]);

    auto check = [&](int k) {
        for (auto &e : ds[abs(k)]) {
            if (sa.count(e) and sb.count(k / e)) return true;
            if (sa.count(-e) and sb.count(k / (-e))) return true;
        }
        return false;
    };
    map<int, bool> ans;

    while (q--) {
        int x;
        cin >> x;
        if (ans.count(x)) {
            if (ans[x])
                cout << "YES" << el;
            else
                cout << "NO" << el;
            continue;
        }
        bool ok = check(x);
        ans[x] = ok;
        if (ok) {
            cout << "YES" << el;
        } else
            cout << "NO" << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}