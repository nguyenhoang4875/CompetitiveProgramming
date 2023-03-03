#include<bits/stdc++.h>

using namespace std;

/**
 * https://codeforces.com/contest/1800/problem/A
*/

int tcs, n;
string s;

void solve() {
    cin >> n;
    cin >> s;

    // lower case 
    int len = s.length();
    for (int i = 0; i < len; i++) {
        s[i] = tolower(s[i]);
    }

    string ans;
    for (int i = 1; i <= len -1; i++) {
        if(s[i+1] != s[i]) {
            ans.push_back(s[i]);
        }
    }
    if (s[0] != s[1]) {
        ans = s[0]+ans;
    }

    if(ans.compare("meow") == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
   
}
int main() {
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    
    return 0;
}