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
// int a[200005];

void solve() {
    cin >> n;
    int sum = 0;
    int x;
    n--;
    for(int i = 1; i <= n; i++ ) {
        cin >> x;
        sum += x;
    }
    n++;
    int total = n * (n + 1) / 2;
    cout << (total - sum) << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}