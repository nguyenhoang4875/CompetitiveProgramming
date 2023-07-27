#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/gym/458493/problem/A
*/

int n;
int m[5];       // money
int a[100005];  //

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 25) {
            m[1]++;
        }
        if (a[i] == 50) {
            if (m[1] >= 1) {
                m[1]--;
                m[2]++;
            } else {
                cout << "NO\n";
                return;
            }
        }
        if (a[i] == 75) {
            if (m[2] >= 1) {
                m[2]--;
                m[3]++;
            } else if (m[1] >= 2) {
                m[1] -= 2;
                m[3]++;
            } else {
                cout << "NO\n";
                return;
            }
        }
        if (a[i] == 100) {
            if (m[3] >= 1) {
                m[3]--;
                m[4]++;
            } else if (m[2] >= 1 && m[1] >= 1) {
                m[2]--;
                m[1]--;
                m[4]++;
            } else if (m[1] >= 3) {
                m[1] -= 3;
                m[4]++;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}