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
const int ms = 2e5 + 5;
int n, tmp;
int a[ms];

void solve() {
    cin >> n;
    For(i, 1, n) {
        cin >> a[i];
    }
    int maxDup = 1;
    int ans = 0;
    int cnt1 = 0, cnt2 = 0;
    int f = a[1], l = a[n];
    int i;
    i = 1;
    while(i <= n and a[i] == f) i++;
    cnt1 = i - 1;
    ans = cnt1; 
    i = n;
    while(i >= 1 and a[i] == l) i--;
    cnt2 = n - i;
    ans = max(ans, cnt2); 
    if(f == l) {
        ans = min(cnt1 + cnt2, n);
    }
    cout << (n - ans) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}