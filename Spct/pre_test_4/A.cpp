#include<bits/stdc++.h>

using namespace std;

//*** START CODING ***//

int tcs, n;
string s;

bool isSubstring(string inp) {
    int size = inp.size();
    for (int i = 0; i < size; i++) {
        if (inp[i] != 'a' && inp[i] != 'b' && inp[i] != 'c') return false;
    }
    for (int i = 0; i < size - 1; i++) {
        if (inp[i] == 'a' && inp[i+1] != 'b') return false;
        if (inp[i] == 'b' && inp[i+1] != 'c') return false;
        if (inp[i] == 'c' && inp[i+1] != 'a') return false;
    }
    return true;
}

void solve() {
    cin >> s;
    string ans = isSubstring(s) ? "YES" : "NO";
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}