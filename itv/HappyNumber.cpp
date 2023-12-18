#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://leetcode.com/problems/happy-number/description/
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

bool isHappy(int n) {
    unordered_set<int> si;
    while (!si.count(n)) {
        si.insert(n);
        int temp = 0;
        while (n > 0) {
            temp += (n % 10) * (n % 10);
            n /= 10;
        }
        n = temp;
        if (n == 1) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    cout << isHappy(n) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}