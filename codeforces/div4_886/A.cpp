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

int tcs, n;
struct node {
    int id, a, b;
};

void solve() {
    cin >> n;
    vector<node> v;
    int a, b;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        v.pb({i, a, b});
    }
    sort(v.begin(), v.end(), [&](node n1, node n2) {
        return n1.b > n2.b;
    });

    for(auto e: v) {
        if(e.a <= 10) {
            cout << e.id << '\n';
            return;
        }
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}