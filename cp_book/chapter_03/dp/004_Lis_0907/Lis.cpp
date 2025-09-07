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

// O(n log n)
int lisGeedy(vector<int>& a) {
    int n = a.size();
    vector<int> ans = {a[0]};

    for (int i = 1; i < n; i++) {
        if (a[i] > ans.back()) {
            ans.push_back(a[i]);
        } else {
            int idx = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[idx] = a[i];
        }
    }
    return ans.size();
}

// O(n ^ 2)
int lisBu(vector<int>& a) {
    int n = a.size();
    vector<int> f(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, f[i]);
    return ans;
}

vector<int> a, memo;

// O(n ^ 2)
int lisTd(int i) {
    if (i == 0) return 1;
    int& ans = memo[i];
    if (ans != -1) return ans;
    ans = 1;
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i]) ans = max(ans, lisTd(j) + 1);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    Rep(i, n) cin >> a[i];
    cout << lisGeedy(a) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}