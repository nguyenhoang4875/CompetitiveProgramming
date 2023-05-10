#include<bits/stdc++.h>
#define int long long

using namespace std;

int n;

int c2n(int n) {
    return n * (n-1) / 2;
}

void solve() {
    cin  >> n;
    map<int, int> mi;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        mi[x]++;
    }  
    int cnt = 0;
    for (auto e: mi) {
        if(e.second >= 2) {
            for (auto e2: mi) {
                if(e.first != e2.first && e2.first < 2 * e.first) {
                    cnt += c2n(e.second) * e2.second;
                }
                if(e2.first >= 2 * e.first) break;
            }
        }
    }
    cout << cnt << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}