#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    cin >> n;
    map<int, int> mi;
    int x;
    for (int i = 0; i < n ; i++) {
        cin >> x;
        mi[x]++;
    }
    string s1 = "";
    vector<int> ve;
    int lastKey = (--mi.end())->first;

    int cnt = 1;
    for (pair<int , int > p : mi) {
        if(p.first != lastKey) {
            s1 += to_string(p.first) +" ";
            cnt++;
            if(p.second >= 2) {
                ve.push_back(p.first);
                cnt++;
            }
        }
    }
    ve.push_back(lastKey);
    reverse(ve.begin(), ve.end());
    string s2 = "";
    for (int i = 0; i < ve.size(); i++) {
        s2 += to_string(ve[i]) +" ";
    }
    cout << cnt << endl;
    cout << s1 << s2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
   cin.tie(nullptr);

    tcs = 1;
    while (tcs--) {
        solve();
    }
    return 0;
}