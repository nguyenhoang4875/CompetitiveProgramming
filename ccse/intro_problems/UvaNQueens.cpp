#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
vector<int> col, diag1, diag2;
int cnt = 0;
char a[20][20];

// set<int> fixCol;

void search(int r) {
    if(r == n) {
        cnt++;
        return;
    }
    for(int c = 0; c < n; c++) {
        if(a[r][c] == '*' || col[c] || diag1[c + r] || diag2[c - r + n - 1]) continue;
        col[c] = diag1[c + r] = diag2[c - r + n - 1] = 1;
        search(r + 1);
        col[c] = diag1[c + r] = diag2[c - r + n - 1] = 0;
    }
}

void solve() {
    int tc = 1;
    while(cin >> n) {
    if(n == 0) return;
    cnt = 0;
    col.assign(n, 0);
    diag1.assign(2*n, 0);
    diag2.assign(2*n, 0);
    char c;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    // cout << "n = " << n << '\n';

    search(0);
    printf("Case %d: %d\n", tc, cnt);
    tc++;
    }

}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}


