#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://atcoder.jp/contests/abc169/tasks/abc169_d
 * Solution: Math
 * - find PrimeDivisors
 * 
 * TC: O(log n)
 * MC: O(log n)
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
int n;


void solve() {
    cin >> n;
    if(n == 1) {
        cout << "0\n";
        return;
    }
    int tmp = n;
    int cnt = 0;
    int i = 2;
    int tc = 0;
    while(n && i * i <= tmp) {
        while(n % i == 0) {
            tc++;
            n /= i;
        }
        for(int j = 1; j <= tc; j++) {
            if(j <= tc) {
                tc -= j;
                cnt++;
            }
        }
        tc = 0;
        i++;
    }
    if(n > 1) cnt++;
    cnt = max(cnt, 1LL);
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}