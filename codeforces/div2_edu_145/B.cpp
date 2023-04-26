#include<bits/stdc++.h>

using namespace std;
/**
 * https://codeforces.com/contest/1809/problem/B
*/

int tcs;
long long n;
map<int, long> memo;
long long oo = 1e18;

void solve() {
    cin >> n;
    n--;
    cout <<  (long long) sqrtl(n) << endl;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tcs;
    while(tcs--) {
        solve();
    }
    
    return 0;
}