#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

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

// O(n log n) // longest decreasing subsequence
int lds(vector<int>& a) {
    int n = a.size();
    vector<int> ans = {a[0]};

    for (int i = 1; i < n; i++) {
        if (a[i] < ans.back()) {
            ans.push_back(a[i]);
        } else {
            int idx = lower_bound(ans.begin(), ans.end(), a[i], greater<int>()) - ans.begin();
            ans[idx] = a[i];
        }
    }
    return ans.size();
}

void solve() {
    int n;
    cin >> n;
    vii a(n);
    Rep(i, n) {
        int u, v;
        cin >> u >> v;
        if (u < v) swap(u, v);
        a[i] = {u, v};
    }
    sort(all(a));
    vi b(n);
    Rep(i, n) b[i] = a[i].S;
    int ans = lds(b);
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}