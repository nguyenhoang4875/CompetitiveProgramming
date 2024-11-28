#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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
const int ms = 2e5 + 5;
int n, m;

void solve() {
    cin >> n >> m;
    multiset<int> mts;
    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        mts.insert(tmp);
    }
    int sum = 0;
    bool ok = true;
    for(int i = 1; i <= m; i++) {
        int tmp;
        cin >> tmp;

        auto low = mts.lower_bound(tmp);
        if(low == mts.end()) {
            ok = false;
        } else {
            sum += *low;
            mts.erase(low);
        }
    }
    if(!ok) sum = -1;
    cout << sum << el;



}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}