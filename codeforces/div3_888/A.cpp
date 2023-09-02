#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//

int tcs, n, m , k, H;
int h[55];

void solve() {
    cin >> n >> m >> k >> H;
    set<int> s;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
        int t = abs(H - h[i]);
        if(t % k == 0 && t / k >= 1 && t / k <= m - 1) cnt++;
        
    }
    cout << cnt  << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}