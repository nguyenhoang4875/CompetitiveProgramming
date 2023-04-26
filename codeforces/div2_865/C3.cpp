#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[300005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n == 2 && a[1] > a[2]) {
        cout << "NO" << endl;
        return;
    }

    bool gr = false;
    bool k
    int k = 0;
    int cnt = 0;
    for (int i = 2; i <= n ; i++) {
        if(a[i] != a[i-1]) {
            k = i;
            cnt = 1;
            gr = (a[i] > a[i-1]);
            break;
        }
    }
    bool next;
    for (int i = k + 1; i <= n ; i++) {

        if((a[i] > a[i-1]) != gr) {
            gr = !gr;
            cnt++;
        }
    }
     cout << "k= " << k << endl;
     cout << "cnt = " << cnt << endl;
    if(cnt <= 2) {
        cout << "YES" << endl;

    } else {
        int sum = 0;
        for (int i = 2; i <= n ;i++) {
            sum += a[i] - a[i-1];
        }
        if(sum >= 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    
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