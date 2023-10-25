#include<bits/stdc++.h>
#define int long long

using namespace std;

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
#define For(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it,x) for(auto it = x.begin(); it != x.end(); ++it)

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

const int oo = 1e9, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n, m, k;

int countForRow(vvc &a, int r, int v)  {
    int cover = 0;
    int cnt = 0;
    for(int c = 1; c <= m; c++) {
        if(a[r][c] == '#') {
            cover = c;
            continue;
        }
        if(a[r][c] == 'x') {
            if(cover < c) {
                cnt++;
                cover = c + 2*v;
            } 
        }
    }
    // debug(v);
    // debug(r);
    // debug(cnt);
    return cnt;
}

bool check(vvc& a, int val) {
    int cnt = 0;
    for(int r = 1; r <= n; r++ ) {
       cnt += countForRow(a, r, val);
    }
    return cnt <= k;
}


void solve() {
    cin >> n >> m >> k;

    vvc a(n + 1, vc(m + 1));
    int cntRowHasX = 0;
    For(i, 1, n) {
        bool hasX = false;
        For(j, 1, m) {
            cin >> a[i][j];
            if(!hasX && a[i][j] == 'x') hasX = true;
        }
        if(hasX) cntRowHasX++;
    }

    // debug(a);

    if(cntRowHasX > k) {
        cout << "-1\n";
        return;
    }

    int ans = -1;
    int l = 0, r = 1e6;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(a, mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}