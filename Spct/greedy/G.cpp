#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codeforces.com/contest/401/problem/C
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int n, m;

void solve() {
    cin >> n >> m;
    int sz = m + n;
    if(n > m + 1 || m > (n + 1) * 2) {
        cout << "-1";
        return;
    }
    if(n >= m) {
        for(int i = 1; i <= sz; i++) {
            if(i % 2 == 1) cout << '0';
            else cout << '1';
        }
    }
    else if(m >= 2 * n) {
       for(int i = 1; i <= sz; i++) {
        if(i % 3 == 0) cout << '0';
        else cout << '1';
       }
       return;
    } else {
        int t1 = 2*n - m;
        int t2 = m - n;
        for(int i = 1; i <= 3*t2; i++) {
            if(i % 3 == 0) cout << '0';
            else cout << '1';
        }
        for(int i = 1; i <= 2*t1; i++) {
            if(i % 2 == 1) cout << '1';
            else cout << '0';
        }
    }
    cout << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}