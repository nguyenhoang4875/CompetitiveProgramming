#include<bits/stdc++.h>
using namespace std;
/**
 * https://codeforces.com/contest/1789/problem/A
*/
int tcs, n;
vector<int> vi;

void solve() {
    cin >> n;
    vi.clear();
    for (int i = 1; i <= n ; i++) {
        int x; 
        cin >> x;
        vi.push_back(x);
    }
    for (int i =0; i <= n - 2; i++) {
        for (int j = i+1; j <= n - 1; j++) {
            if(__gcd(vi[i], vi[j]) <= 2) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
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