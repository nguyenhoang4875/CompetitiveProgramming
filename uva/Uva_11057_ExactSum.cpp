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
const int ms = 1e4 + 5;
int n, m;
int a[ms];

void solve() {
    while(cin >> n) {
        For(i, 1, n) cin >> a[i];
        cin >> m;
        sort(a + 1, a + n + 1);
        int diff = oo;
        int l = -1, r = -1;
        for(int i = 1; i <= n; i++) {
            if(a[i] > m/2 + 1) break;
            int val = m - a[i];
            if(binary_search(a + i + 1, a + n + 1, val)) {
                if(val - a[i] < diff) {
                    l = a[i];
                    r = val;
                }
            }
        }
        cout << "Peter should buy books whose prices are "<< l << " and " << r <<  "." << el;
        cout << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve(); 
    return 0;
}