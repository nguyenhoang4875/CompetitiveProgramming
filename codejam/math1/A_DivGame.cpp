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
const int ms = 2e5 + 5;
int n;

map<int, int> getPrimeFactors(int n) {
    map<int, int> ans;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ans[i]++;
            n /= i;
        }
    }
    if (n != 1) ans[n]++;
    return ans;
}

void solve() {
    cin >> n;
    map<int, int> m = getPrimeFactors(n);
    int ans = 0;
    for(auto e: m) {
        int cnt = 0; 
        int tmp = 0;
        while(tmp < e.S) {
           tmp++; 
           e.S -= tmp;
           cnt++;
        }
        ans += cnt;
        // cout << "cnt = " << cnt << el;
    }
    cout << ans << el;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}