#include<bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/gym/482326/problem/C
 * Solution: Handle for six cases:
 *  - m == 1 and n == 1
 *  - n = 1 or m == 1
 *  - n < m
 *  - n == m
 *  - n > m
 * 
 * TC:(n * m)
 * MC: O(n * m)
 * 
*/

//*** debug(x) ***//
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl

#if 1
template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x)os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")" ;
}
#endif

template<typename T>
void check_here(T x){
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
int n, m;

void solve() {
    cin >> n >> m;
    if(n == 1 and m == 1) {
        cout << "0\n";
        cout << "0\n";
        return;
    }
    if(n == 1) {
        cout << "2\n";
        For(i, 0, m - 1) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    if(m == 1) {
        cout << "0\n";
        For(i, 0, n - 1) {
            cout << "0\n";
        }
        return;
    }
    if(n < m) {
        cout << n + 1 << "\n";
        For(i, 0, n - 1) {
            For(j, 0, m - 1) {
                cout << (j - i + m) % m << " ";
            }
            cout << "\n";
        }
    } else if(n == m) {
        cout << n << "\n";
        For(i, 0, n - 2) {
            For(j, 0, m - 1) {
                cout << (j - i + m) % m << " ";
            }
            cout << "\n";
        }
        For(j, 0, m - 1) {
            cout << j << " ";
        }
        cout << "\n";

    } else {
        // n > m
        cout << m << "\n";
        For(i, 0, m - 2) {
            For(j, 0, m - 1) {
                cout << (j - i      + m) % m << " ";
            }
            cout << "\n";
        }
        For(i, m - 1, n - 1) {
            For(j, 0, m - 1) {
                cout << j << " ";
            }
            cout << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}