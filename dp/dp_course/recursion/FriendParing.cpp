#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Given n friends who want to go to the party, each one can 
 * remain single or can be paired up with some other friend.
 * Each friend can be paired only once. Find out the
 * total number of ways in which friends can remain single
 * or can be paired up.
 * 
 * Solution: f(n) = f(n - 1) + (n - 1) * f(n - 2)
 * 
*/

int f(int n) {
    if(n == 0 || n == 1) return 1;
    return f(n- 1) + (n - 1) * f(n - 2);
}


void solve() {
    int n;
    cin >> n;
    cout << f(n) << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}