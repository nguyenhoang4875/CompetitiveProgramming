#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Given a number n, check if n is symmetric number
 * symmetric number is the same if look from left to right or right to left
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

bool isSymmetric(int n) {
    int revNum = 0;
    int num = n;
    while (n) {
        revNum *= 10;
        revNum += n % 10;
        n /= 10;
    }
    return revNum == num;
}

void solve() {
    cin >> n;
    cout << isSymmetric(n) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}