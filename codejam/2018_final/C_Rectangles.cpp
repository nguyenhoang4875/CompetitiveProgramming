#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

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



const int MS = 1e5 + 5;

int n;
int a[MS];

int32_t main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    vector<int> v;
    for (int i = n - 1; i > 0; i--) {
        if (a[i + 1] - a[i] < 2) {
            v.pb(a[i]);
            i--;
        }
    }
    // debug(v);
    int ans = 0;
    for (int i = 0; i + 1 < v.size(); i += 2) {
        ans += v[i] * v[i + 1];
    }
    cout << ans << '\n';
}
