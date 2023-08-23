#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/21397
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//

int tcs, n, a, b, c;
int p10[20];

void init() {
    p10[0]  = 1;
    for(int i = 1; i < 20; i++) {
        p10[i] = p10[i - 1] * 10;
    }
}

int lent(int x) {
    string s = to_string(x);
    return s.size();
}

int getLen(int x, int b, int a) {
    if(a == 0) a += b;
    if(x == b) return lent(x);
    int xl = lent(x);
    
    int ans = 0;
    for(int len = 1; len <= xl; len++) {
        int k1 = (p10[len - 1]  - a + b - 1) / b;
        int k2 = (p10[len] - 1 - a) / b;
        if(len == xl) {
            k2 = (x - a) / b;
        }
        int x1 = a + k1 * b, x2 = a + k2 * b;
        if(k1 <= k2 && p10[len - 1] <= x1 && x2 < p10[len]) {
            ans += (k2 - k1 + 1) * len;
        }
    }
    return ans;
}

int total(int a, int b, int k) {
    int x2 = a + b * k;
    int v2 = getLen(x2, b , a % b);

    int x1 = a - b;
    int v1 = 0;

    if(x1 > 0) v1 = getLen(x1, b, a % b);
    return v2 - v1;
}

void solve() {
    cin >> a >> b >> c;

    int l = 0, r = 1;
    while(total(a, b, r) <= c) r *= 2;
    
    while(l <= r) {
        int mid = (l + r) / 2;
        if(total(a, b, mid) >= c) r = mid - 1;
        else l = mid + 1;
    }
    int x = a + b * l;
    int len = total(a, b, r);
    string s = to_string(x);
    int idx = c - len - 1;
    cout << s[idx] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}