#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Count the number of binary strings with no consecutive ones
 * that can be formed using binary string of length n;
 * 
 * Input: N
 * Output: Count of Strings
 * 
 * Solution: f(n) = f(n - 1) + f(n - 2)
 * Time: Recursion: O(2^n), DP O(n)
 * 
*/

int n;
int cal(int n) {
    if(n < 1) return 1;
    return cal(n - 1) + cal(n - 2);
}

void solve() {
    cin >> n;
    cout << cal(n) << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}