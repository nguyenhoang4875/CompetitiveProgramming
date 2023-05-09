#include<bits/stdc++.h>

using namespace std;

//******************** define *********************//
#define int long long
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)

//******************** typedef *********************//
// typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;

//******************* debug(x) *********************//
//****https://codeforces.com/blog/entry/68920****//

//#define watch(x) cout << "[" << #x << "]" << " : " << (x) << endl
//#define getName(var) #var
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

//****************** START CODING **********************//

int tcs, n;

void solve() {
   map <int, int> m{ {10, 2}, {11, -2}, {-6, 4} };
    float i = 10.019;
    string s = "this is a string";
    unordered_map <int, int> um{ {10, 2}, {11, -2}, {-6, 4} };
    vector <string> vs{"heh", "hah"};
    vector <vector <int>> vvi{{1, 2}, {5, 6, 8}, {}};
    vector<int> vi{1, 3, 5, 7, 8};
    vector<char> vc{'a', 'c', 'f'};
    vector<pair<int, string>> vpi{ {10, "muoi"}, {11, "muoi mot"}, {-6, "bon"}, {}, {12, "muoi hai"} };
    set <string> ss{"heh", "hah"};
    set <set <int>> ssi{{1, 2}, {5, 6, 8}, {}};
    const char* cs = "hah";
    char c = 's';

    debug(m);
    debug(i);
    debug(s);
    debug(um);
    debug(vs);
    debug(vvi);
    debug(vi);
    debug(vc);
    debug(vpi);
    debug(ss);
    debug(ssi);
    debug(cs);
    debug(c);
	check_here(123);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// cin >> tcs;
	tcs = 1;
	while(tcs--) {
		solve();	
	}
	return 0;
}