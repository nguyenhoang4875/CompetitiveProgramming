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

//*** START CODING ***//

int n, m;
vi v10;
vi vn10;
void solve() {
    cin >> n >> m;
    int cnt = 0;
    int sum = 0;
    int can10 = 0;
    int x;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x < 10) continue;
        if(x == 10) {
            cnt++;
            continue;
        } 
        if(x % 10 == 0) v10.pb(x);
        else vn10.pb(x);
        can10 += x / 10;
    }
    if(m >= can10) {
        cout << (cnt + can10) << '\n';
        return;
    }
    sort(v10.begin(), v10.end());
    sort(vn10.begin(), vn10.end());

    int vz = v10.size();
    for(int e: v10) {
        int t = e / 10;
        if(m >= (t - 1)) {
            cnt += t;
            m -= (t - 1);
        }
        else {
            cnt += m;
            m = 0;
        } 
    }

    for(auto e: vn10) {
        int t = e / 10;
        if(m >= t) {
            cnt += t;
            m -= t;
        }
        else {
            cnt += m;
            m = 0;
        } 
    }
    cout << cnt << '\n';


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}