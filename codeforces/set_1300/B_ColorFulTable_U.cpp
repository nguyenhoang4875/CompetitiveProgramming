#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/gym/482326/problem/B
 * Unsolved
 *
 * Observed:
 *  - Always with and hight is same: 1->5 and 5->1 is also 1
 *  - Find left most index and right most index element
 *    which is greater and equal to current
 *  - Using two pointer to find for each color
 * 
 * TC: O(n * log n)
 * MC: O(n)
 */

//*** debug(x) ***//
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl

#if 1
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
#endif

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}

//*** define ***//
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
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
int n, k;

void solve() {
    cin >> n >> k;
    vi a(n);
    set<int> si;  // using set to find with time O(log n)
    For(i, 0, n - 1) {
        cin >> a[i];
        si.insert(a[i]);
    }

    map<int, pii> colorRec;
    int color = 1;
    int l = 0, r = n - 1;
    // using two pointer to find rectangle for each color
    while (l <= r) {
        if (a[l] >= color and a[r] >= color) {
            colorRec[color] = {l, r};
            color++;
        }
        if (a[l] < color) l++;
        if (a[r] < color) r--;
    }
    For(i, 1, k) {
        if (si.find(i) == si.end()) {
            cout << "0 ";
        } else {
            cout << 2 * (colorRec[i].S - colorRec[i].F + 1) << " ";
        }
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}