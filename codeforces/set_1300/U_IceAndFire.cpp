#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/gym/482326/problem/U
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
const int ms = 2e5 + 5;
int n;
char a[ms];

void solve() {
    cin >> n;
    char preChar;
    int preVal;
    For(i, 2, n) {
        char c;
        cin >> c;
        if(i == 2) {
            preVal = 1;
            cout << preVal << " ";
        } else {
            if(c == preChar) {
                cout << preVal << " ";
            } else {
                cout << i - 1 << " ";
                preVal = i - 1;
            }
        }

        preChar = c;
    }
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