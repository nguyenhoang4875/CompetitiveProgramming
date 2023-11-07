#include <bits/stdc++.h>

using namespace std;
/**
 * Problem: https://cses.fi/problemset/task/1081
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

const int ms = 2e5 + 5;
const int nax = 1e6 + 1;
int n;
int divisor[nax];

void solve() {
    cin >> n;
    For(i, 1, n)  {
        int x;
        cin >> x;
        for(int t = 1; t*t <= x; t++) {
            if(x % t == 0) {
                divisor[t]++;
            
                if(t * t != x) divisor[x/t]++;
            }
        }
    }

    for(int i = 1e6; i >= 1; i--) {
        if(divisor[i] >= 2) {
            cout << i << el;
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}