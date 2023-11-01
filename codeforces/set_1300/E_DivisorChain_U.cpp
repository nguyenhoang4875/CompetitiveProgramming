#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/gym/482326/problem/E
 * Solution: find max n that 2^n <= x then spit two parts
 *  - part 1: 1 -> 2^n
 *  - part 2: 2^n + 1 -> x
 * 
 * TC: O(log n)
 * MC: O(n)
 * 
*/

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int x;

int getBit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void solve() {
    cin >> x;
    vi ans;
    int i = 0;
    int p = 0;
    ans.pb(x);
    while(true) {
        if(getBit(x, i)) {
            if(x == 1 << i) {
                p = i;
                break;
            }
            x -= (1 << i);
            ans.pb(x);
        }
        i++;
    }
    while(p) {
        x -= (1 << (p - 1));
        ans.pb(x);
        --p;
    }
    cout << sz(ans) << el;
    for(auto e: ans) cout << e << " ";
    cout << el;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}