#include <bits/stdc++.h>
#define int long long

using namespace std;

void genBracket(vector<string>& v, string s, int l, int r, int n) {
    // base case
    if(s.size() == 2*n) {
        v.push_back(s);
    }

    // rec case
    if(l < n) {
        genBracket(v, s + '(', l + 1, r, n);
    }
    if(l > r) {
        genBracket(v, s + ')', l , r + 1, n);
    }

}

void solve() {
    int n;
    cin >> n;
    vector<string> ans;
    genBracket(ans,"", 0, 0, n);
    for(string s: ans) {
        cout << s << '\n';
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}