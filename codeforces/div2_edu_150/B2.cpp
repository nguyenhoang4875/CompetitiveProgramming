#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[200005];
int b[200005];
vector<int> x;


void solve() {
    x.clear();
    cin >> n;
    int num;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if(i == 1) {
            cout << 1;
            cnt = 1;
            x.push_back(num);
            continue;
        }

        int newCnt = cnt;
        newCnt -= x.back() <= x[0];
        newCnt += x.back() <= num;
        newCnt += num <= x[0];

        if(newCnt >= x.size()) {
            cout << 1;
            cnt = newCnt;
            x.push_back(num);
        } else {
            cout << 0;
        }
    }
    
    cout << '\n';

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