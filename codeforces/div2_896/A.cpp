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

int n;
int a[105];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n & 1) {
        cout << "4\n";
        cout << "1 " << n - 1 << '\n';
        cout << "1 " << n - 1 << '\n';
        cout << n - 1 << " " <<  n << '\n';
        cout << n - 1 << " " <<  n << '\n';

    } else {
        cout << "2\n";
        cout << "1 " << n <<"\n";
        cout << "1 " << n <<"\n";
    }

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