#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;

void solve() {
    cin >> n;
    cout << n << ' ';
    while(n != 1) {
        if(n % 2 == 0) n /= 2;
        else {
            n *= 3;
            n++;
        }
        cout << n << ' ';
    }
    cout << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}