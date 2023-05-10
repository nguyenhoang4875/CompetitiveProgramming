#include<bits/stdc++.h>
using namespace std;
/**
 * https://codeforces.com/contest/1794/problem/B
*/
int tcs, n;

void solve() {
    cin >> n;
    vector<int> vi;
    int x;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        if(x == 1) x++;
        vi.push_back(x);
    }
    for (int i = 1; i < n ; i++) {
        if(vi[i] % vi[i-1] == 0) {
            vi[i]++;
        }
    }
    for (int e: vi) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tcs;
    while(tcs-- > 0) {
        solve();
    }
    return 0;
}