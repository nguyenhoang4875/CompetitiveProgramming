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
int a[5005];
int preSum[5005];

bool canTwoSum(int l, int r) {
    int sum = preSum[r] - preSum[l - 1];
    if(sum & 1) return false;
    int half = sum / 2;

    int tl = l, tr = r;
    while(tl <= tr) {
        int tm = (tl + tr) / 2;
        if(preSum[tm] - preSum[l - 1] < half) {
            tl = tm + 1;
        } else if(preSum[tm] - preSum[l - 1] > half) {
            tr = tm - 1;
        } else {
            return true;
        }
    }
    return false;

}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        preSum[i] = preSum[i - 1] + a[i];
    }

    int ans = 0;
    for(int l = 1; l <= n; l++) {
        for(int r = l + 1; r <= n; r++) {
            if(canTwoSum(l, r)) {
                ans = max(ans, r - l + 1);
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