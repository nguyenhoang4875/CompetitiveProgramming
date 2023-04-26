#include<bits/stdc++.h>

using namespace std;
/**
 * https://codeforces.com/contest/1807/problem/A
*/

int tcs, n;
string s;
unordered_set<char> ss;

void solve() {
    ss.clear();
    cin >> n;
    cin >> s;
    if(n == 1) {
        cout << "YES" << endl;
        return;
    }

    for (char c: s) {
        ss.insert(c);
    }

    for (char cc: ss) {
        int index = -1;
        for (int i = 0; i < n ; i++) {
            if(s[i] == cc)
                if(index == -1) index = i;
                else {
                    if((i - index) % 2 != 0) {
                        cout << "NO" << endl;
                        return;
                    }
            }
        }
    }
    cout << "YES" << endl;
   
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