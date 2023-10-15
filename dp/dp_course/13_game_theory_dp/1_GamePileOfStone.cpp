#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: Alice and Bob are playing a game of a pile of stones
 * Initially there are n stones in a pile.
 * A player can pick 1, 2, 3, stones from a pile.
 * Alice play first and players plays alternatively.
 * The player who is unable to move looses the game.
 *
 * For Alice
 * n: 0 1 2 3 4 5 6 7 8 ...
 *    L W W W L W W W L ...
 *
 * fn = !(f(n-1) && f(n-2) && f(n-3))
 * or:
 * if(n %4 == 0) Alice wins else looses
 */

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
int n;

void solve() {
    cin >> n;
    if (n % 4 == 0) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}