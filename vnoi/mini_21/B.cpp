#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int n;
vector<int> can;
vi cnt;

const int mx = 1e13;
const int im = 4e6;

bool check(int x) {
    cnt.assign(10, 0);
    string s1 = to_string(x);
    for (auto c : s1) cnt[c - '0']++;
    string s2 = to_string(x * x);
    for (auto c : s2) cnt[c - '0']++;
    for (int i = 0; i <= 9; i++) {
        if (cnt[i] > 2) return false;
    }
    return true;
}

void init() {
    for (int i = 1; i <= im; i++) {
        if (i * i >= mx) break;
        if(check(i)) can.pb(i);
    }
}


void solve() {
    cin >> n;
    auto t = lower_bound(can.begin(), can.end(), n);
    if(t == can.end()) {
        cout << "-1\n";
        return;
    }
    cout << *t << '\n';
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    init();

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}