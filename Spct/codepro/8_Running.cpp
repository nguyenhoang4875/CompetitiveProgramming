#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int) (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int) (b); i--)
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
int n, t;

void solve() {
    cin >> n >> t;
    vector<int> v(n); // position of i-th at t time
    for(int i = 0; i < n; i++) {
        int p, s;
        cin >> p >> s;
        v[i] = p + s * t;
    }

    /*
        Print number groups,
        Pint the number of the the rightmost int each group, print from right to left

        if at time t:
        i-th has position p1
        i - 1 has position p2
        if(p2 >= p1) => i and i - 1 same group
    */

    vector<int> ans;
    int cur = v[n - 1];
    ans.push_back(n);
    for(int i = n - 1; i >= 0; i--) {
        if(cur <= v[i]) continue;
        cur = v[i];
        ans.push_back(i + 1);
    }
    cout <<  ans.size() << el;

    for(auto e: ans) cout << e << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}