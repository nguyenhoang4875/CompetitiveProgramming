#include<bits/stdc++.h>
using namespace std;
/**
 * https://codeforces.com/contest/1703/problem/A
*/
int tcs, n;

void solve() {
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if(s.compare("yes") == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}


int main() {
    cin >> tcs;
    while(tcs-- > 0) {
        solve();
    }

    return 0;
}