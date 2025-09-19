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

int lbs(vector<int>& a) {
    int n = a.size();
    vector<int> l(n, 1), d(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j]) l[i] = max(l[i], l[j] + 1);
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (a[i] > a[j]) d[i] = max(d[i], d[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) ans = max(ans, l[i] + d[i] - 1);
    return ans;
}

// O(n^2) longest bitonic sequence start from i to right: both lis and lds
int lbsItoRight(vector<int>& a) {
    int n = a.size();
    vector<int> l(n, 1), d(n, 1);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (a[i] < a[j]) l[i] = max(l[i], l[j] + 1);
            if (a[i] > a[j]) d[i] = max(d[i], d[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) ans = max(ans, l[i] + d[i] - 1);
    return ans;
};

void solve() {
    int n;
    cin >> n;
    vi a(n);
    Rep(i, n) cin >> a[i];

    cout << lbs(a) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}