#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/group/Tb6c29cXIE/contest/458493/problem/D
*/

int n, k;
string s;

void solve() {
    cin >> s >> k;
    n = s.size();
    map<char, int> mci;
    for(int i = 0; i < n; i++) {
        mci[s[i]]++;
    }

    vector<pair<char, int>> v;
    for(auto e: mci) {
        v.push_back(e);
    }

    sort(v.begin(), v.end(), [&](pair<char, int> p1, pair<char, int> p2) {
        return p1.second < p2.second;
    });
    int total = v.size();
    for(int i = 0; i < v.size(); i++) {
        if(k >= v[i].second) {
            k -= v[i].second;
            v[i].second = 0;
            total--;
        } else {
            v[i].second -= k;
            break;
        }
    }
    cout << total << "\n";
    string ans= "";
    for(int i = 0; i < n; i++) {
        for(auto e: v) {
            if(e.first == s[i] && e.second > 0) {
                ans += s[i];
                e.second--;
            }
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}