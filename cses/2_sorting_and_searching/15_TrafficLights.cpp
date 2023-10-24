#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Solution: save lights: set, dist: multiset
 * When add a lights:
 *  - break the length contain position of the light by two length
 *  - find the largest length
 * 
 * TC: O(n * log(n))
 * MC: O(n)
 * 
*/

#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it,x) for(auto it = x.begin(); it != x.end(); ++it)

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
int n, x;


void solve() {
    cin >> x >> n;
    set<int> lights = {0, x}; // save position of light
    multiset<int> dist = {x}; // save the length ascending
    For(i, 1, n) {
        int val;
        cin >> val;

        auto up = lights.upper_bound(val);
        auto low = up;
        low--;

        dist.erase(dist.find(*up - *low)); // remove first length (up - low)
        dist.insert(val - *low);
        dist.insert(*up - val);
        lights.insert(val);
        
        auto it = dist.end();

        cout << *prev(dist.end()) << ' ';
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}