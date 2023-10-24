#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second

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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;
int a[ms];

int getSum(int l, int r, vi& sum) {
    if(l == 0) return sum[r];
    else return sum[r] - sum[l - 1];
}

// find largest index i that have a[i] > val
int binarySearch(vi& s, int val) {
    int pos = 0;
    int l = 0;
    int r = s.size() - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[s[mid]] > val) {
            pos = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return pos;

}

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    vi s; // vector(using as stack) will be monotonic decreasing
    vi sum(n + 5, 0);


    int ans = 0;
    For(i, 1, n) {
        while(!s.empty() && a[s.back()] < a[i]) {
            // case a[i] > a[j] with i > j
            if(s.back() != i - 1) ans += i - s.back() + 1;
            s.pop_back();
        }

        // find the the fist element that greater then a[i]
        // l, r in based-index 0
        int l = binarySearch(s, a[i]);
        int r = s.size() - 1;

        // prefixSum of sum that index satisfy
        if(l <= r) ans += i *(r - l + 1) - getSum(l, r, sum) + (r - l + 1);

        // remove i, j sub array length 2
        if(!s.empty() && s.back() == i - 1) {
            ans -= 2;
        }

        s.pb(i);
        int ssize = s.size();
        sum[ssize - 1] = i;
        if(ssize - 2 >= 0) sum[ssize - 1] += sum[ssize - 2];
    }
   
    cout << ans << '\n';
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