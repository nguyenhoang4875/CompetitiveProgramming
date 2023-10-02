#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
vector<int> col, diag1, diag2;
int cnt = 0;

void search(int y) {
    if(y == n) {
        cnt++;
        return;
    }
    for(int x = 0; x < n; x++) {
        if(col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        search(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
}

void solve() {
    cin >> n;
    col.assign(n, 0);
    diag1.assign(2*n, 0);
    diag2.assign(2*n, 0);
    cout << "n = " << n << '\n';

    search(0);
    cout << "count = " << cnt << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}


