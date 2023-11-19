#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/group/AzS2VFYWhz/contest/482326/problem/N
 * Solution: Brute force
 *  - Remove all duplicate elements and add to a set
 *  - Try with length of permutation from 1 to size of set
 *  - Check will case delete all and add 1
 * 
 * TC: O(n)
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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n, c, d;
int p[ms];

void solve() {
    cin >> n >> c >> d;
    int sumDup = 0;
    set<int> si;

    For(i, 1, n) {
        int x;
        cin >> x;
        if(si.count(x)) {
            sumDup += c;
        } else {
            si.insert(x);
        }
    }
    int id = 0;
    for(auto x: si) p[++id] = x; // convert set to array
    int ans = oo;

    // try for each length from 1 to id
    For(i, 1, id) {
        ans = min(ans, 1LL* (id - i) * c + 1LL * (p[i] - i) * d);
    }
    ans = min(ans, 1LL * id * c + d); // case delete all and then add 1
    ans += sumDup;
    cout << ans << el;

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