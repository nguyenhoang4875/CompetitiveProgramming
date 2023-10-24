#include <bits/stdc++.h>
#define int long long

using namespace std;

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
int n;


void solve() {
    int cnt = 1;
    cin >> n;
    int maxVal = 0;
    int minVal = oo;
    multiset<int> mts;
    For(i, 1, n) {
        int x;
        cin >> x;
        auto it = mts.upper_bound(x);
        if(it == mts.end()) mts.insert(x);
        else {
            mts.insert(x);
            // remove only one at it
            mts.erase(it);
        }
    }
    cout << mts.size() << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}