#include <bits/stdc++.h>
#define int long long
/**
 * Problem: https://www.hackerrank.com/contests/apptask-lset-2020-fundamentals-02/challenges
*/

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
int n;
int a[ms];

void solve() {
    cin >> n;
    int ans = -1;
    int cnt = 0;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) {
        if(ans == a[i]) cnt++;
        if(ans < a[i]) {
            ans = a[i];
            cnt = 1;
        }
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}