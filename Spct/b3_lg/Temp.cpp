#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;

void solve() {
    int a[5][5];
    a[0][0] = 10;
    cout << a[0][0] << endl;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            a[i][i] = 100;
            
        }
    }
   

   
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}