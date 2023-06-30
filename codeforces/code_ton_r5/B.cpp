#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, x;
int oo = 1e10;

void solve() {
    cin >> n >> x;
    queue<int> q1, q2, q3;
    int val;
    for(int i = 1; i <= n; i++) {
        cin >> val;
        q1.push(val);
    }
    for(int i = 1; i <= n; i++) {
        cin >> val;
        q2.push(val);
    }
    for(int i = 1; i <= n; i++) {
        cin >> val;
        q3.push(val);
    }
    int sum = 0;
    int sum1, sum2, sum3;
    int sumMin = 0;
    int t1, t2, t3;
    while (!q1.empty() || !q2.empty() || !q3.empty()) {
        if(sum >= x) break;
        // t1 = t2 = t3 = oo;
        t1 = q1.empty() ? oo : q1.front();
        t2 = q2.empty() ? oo : q2.front();
        t3 = q3.empty() ? oo : q3.front();
        cout << t1 << " " << t2 << " " << t3 << endl;

        sum1 = sum | t1;
        sum2 = sum | t2;
        sum3 = sum | t3;
        sumMin = min({sum1, sum2, sum3});
        if(sumMin == sum1) {
            q1.pop();
        } else if(sumMin == sum2) {
            q2.pop();
        } else {
            q3.pop();
        }
        sum = sumMin;

    }
    cout << "sum == " << sum << " x = " << x << endl;
    if(sum == x) {
        cout << "Yes";
    } else cout << "No";
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