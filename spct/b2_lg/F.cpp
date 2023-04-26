#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
char a[105][105];
void solve() {
    cin >> n;
    int total = 0;
    string temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        temp = " " + temp;
        for (int j = 1; j <= n; j++) {
            a[i][j] = temp[j];
            if(a[i][j] == '.') total++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(a[i][j]=='#' && a[i+1][j]=='#' && a[i-1][j]=='#'  && a[i][j+1]=='#'  && a[i][j-1]=='#'  ) {
                a[i][j] = a[i+1][j] = a[i-1][j] = a[i][j-1] =  a[i][j+1] = '.';
                total += 5;
            }
        }
    }
    if(total == n*n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}