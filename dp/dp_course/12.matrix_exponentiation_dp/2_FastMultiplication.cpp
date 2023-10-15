#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: given a, b, c <= 10^15
 * calculate ans = (a * b) % c
 * 
 * Binary multiplication:
 * a * b = a + a + ... + a (b times)
 * => Using binary
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
int n;

int binaryMul(int a, int b, int c) {
    int ans = 0;
    while(b > 0) {
        if(b & 1) ans += a, ans %= c;
        b /= 2;
        a *= 2, a %= c;
    }
    return ans;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << binaryMul(a, b, c);

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}