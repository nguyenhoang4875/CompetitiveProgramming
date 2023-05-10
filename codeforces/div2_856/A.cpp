#include<bits/stdc++.h>
using namespace std;
/**
 * https://codeforces.com/contest/1794/problem/A
*/
int tcs, n;

void solve() {
    string s;
    string first;
    string second;
    cin >> n;

    vector<string> vs;
    vector<string> ans;
    for (int i = 1; i <= 2*n - 2; i++) {
        string s;
        cin >> s;
        vs.push_back(s);
        if(s.length() == n - 1) {
            ans.push_back(s);
        }
    }
    string s1 = ans[0];
    string s2 = ans[1];
    reverse(s1.begin(), s1.end());
    if(s1 == s2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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