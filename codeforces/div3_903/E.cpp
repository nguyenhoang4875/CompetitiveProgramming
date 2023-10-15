#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

//*** debug(x) ***//
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

#if 1
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
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
#define FOR(_i, _a, _b) for (int _i = (_a); _i < (_b); _i++)
#define FORI(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define FORE(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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
const int ms = 1e3 + 5;
int n;
char a[ms][ms];
char b[ms][ms];

void rotate() {
    // First rotation
    // with respect to Secondary diagonal
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            int temp = a[i][j];
            a[i][j] = a[n - 1 - j][n - 1 - i];
            a[n - 1 - j][n - 1 - i] = temp;
        }
    }

    // Second rotation
    // with respect to middle row
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            int temp = a[i][j];
            a[i][j] = a[n - 1 - i][j];
            a[n - 1 - i][j] = temp;
        }
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }

    rotate();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <  n - i; j++) {
            cout << b[i][j];
            // if(a[i][j] != b[i][j]) {
            //     int diff = (int) a[i][j] - (int) b[i][j];
            //     cnt += abs(diff);
            // }
        }
        cout << "\n";
    }
    cout << cnt << '\n';


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t = (int) 'a' ;
    // cout << t << endl;

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}