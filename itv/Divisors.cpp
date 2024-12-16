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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;

vector<int> getDivisors(int n) {
    vector<int> ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i * i != n) ans.push_back(n / i);
        }
    }
    return ans;
}

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
    int n;
    cin >> n;
    vi a = getDivisors(n);
    sort(all(a));
    for (auto e : a) cout << e << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}