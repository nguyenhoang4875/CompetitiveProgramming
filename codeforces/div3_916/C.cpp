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
#define sz(a) (int)(a).size()
#define el '\n'
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
const int ms = 2e5 + 5;
int n, k;
vi a(n), b(n);
int ans = 0;
int memo[ms][ms];

int maximumExperience(int i, int k, int sum) {
    if(k == 0) {
        return 0;
    }
    if(memo[i][k] != -1) return memo[i][k];
    int ans = 0;

    // choose i;
    ans += b[i] + maximumExperience(i, k - 1, sum);
    // choose i + 1;
    if(i  + 1 < n) ans = max(ans,a[i + 1] + maximumExperience(i + 1, k - 1, sum + a[i]));
    // return ans;
    return memo[i][k] = ans;
}

void solve() {
    cin >> n >> k;
    a.clear();
    a.resize(n);
    b.clear();
    b.resize(n);
    memset(memo, -1, sizeof(memo));
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    ans = 0;
    int sum = a[0];
    cout <<a[0] + maximumExperience(0, k - 1, sum) << el;
    // cout << ans << el;




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