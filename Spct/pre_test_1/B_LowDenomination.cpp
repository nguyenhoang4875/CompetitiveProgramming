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
int n = 9;

void solve() {
    int currency[n] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    int cnt[n];
    int cost;

    For(i, 0, n - 1) { cin >> cnt[i]; }

    cin >> cost;
    cost /= 1000;

    vi ans(cost + 1, -1);
    int sum = 0;
    ans[0] = 0;
    For(i, 0, n - 1) {
        sum += currency[i] * cnt[i]; // sum all money possible
        For(j, 1, cost) {
            if(j > sum) break; // break if sum can not reach j
            if(j >= currency[i]) {
                if(ans[j - currency[i]] != -1) {
                    // get max count for each value of j
                    ans[j] = max(ans[j], ans[j - currency[i]] + 1);
                }
            }
        }
    }
    if(ans[cost] == -1) {
        cout << 0 << el;
    } else cout << ans[cost] << el;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}