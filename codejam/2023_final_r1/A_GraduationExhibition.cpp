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
using pii = pair<int, int>;

//*** START CODING ***//

int tcs, n, m;

void solve() {
    cin >> n >> m;
    vvi cnt (n + 5, vi(n + 5, 0));
    for(int i = 1; i <= m; i++) {
        int a, b, v;
        cin >> v >> a >> b;
        cnt[a][b] += v;
    }
    vi hv;
    for(int i = 1; i <= n; i++) hv.pb(i);

    int maxScore = -1, maxCount = 0;
    do {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                sum += cnt[hv[i]][hv[j]];
            }
        }
        if(maxScore < sum) {
            maxScore = sum;
            maxCount = 1;
        }
        else if(maxScore == sum) {
            maxCount++;
        }
    } while(next_permutation(hv.begin(), hv.end()));

    cout << maxScore << " " << maxCount << '\n';

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