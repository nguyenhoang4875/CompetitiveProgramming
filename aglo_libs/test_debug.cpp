#include <bits/stdc++.h>
#define int long long

using namespace std;

#define DEBUG 1
#if DEBUG
#define del cout << '\n'
#define debug(...) cout << "[ " << #__VA_ARGS__ << " ]: ", _debug(__VA_ARGS__)

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p);
template <class Container, typename enable_if<!is_same<Container, string>::value,
                                              decltype(declval<Container>().begin())>::type* = nullptr>
ostream& operator<<(ostream& os, Container const& x);
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Container,
          typename enable_if<!is_same<Container, string>::value, decltype(declval<Container>().begin())>::type*>
ostream& operator<<(ostream& os, Container const& x) {
    int i = 0, n = (int)distance(x.begin(), x.end());
    os << "{ ";
    for (const auto& y : x) os << y << (++i < n ? ", " : "");
    return os << " }";
}
void _debug() { cout << '\n'; }
template <typename T, typename... Args>
void _debug(T first, Args... args) {
    cout << first;
    if (sizeof...(args)) cout << ", ";
    _debug(args...);
}
#else
#define del
#define debug(...)
#endif

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    map<int, int> m{{10, 2}, {11, -2}, {-6, 4}};
    float i = 10.019f;
    string s = "this is a string";
    unordered_map<int, int> um{{10, 2}, {11, -2}, {-6, 4}};
    vector<string> vs{"heh", "hah"};
    vector<vector<int>> vvi{{1, 2}, {5, 6, 8}, {}};
    vector<int> vi{1, 3, 5, 7, 8};
    vector<char> vc{'a', 'c', 'f'};
    vector<pair<int, string>> vpi{{10, "ten"}, {11, "eleven"}, {4, "four"}, {}, {12, "twelve"}};
    set<string> ss{"heh", "hah"};
    set<set<int>> ssi{{1, 2}, {5, 6, 8}, {}};
    const char* cs = "hah";
    char c = 's';
    vector<bool> vb = {1, 1, 1, 0};

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
    debug(vb);

    debug(m, i, s, um, vs, vvi, vi, vc, vpi, ss, ssi, cs, c, vb);

    list<int> my_list = {1, 2, 3};
    deque<string> my_deque = {"a", "b", "c"};

    unordered_set<int> my_uset = {10, 20, 30};
    unordered_map<string, int> my_umap = {{"apple", 5}, {"banana", 3}};

    vector<vector<int>> matrix2d = {{1, 2, 3}, {4, 5}, {6, 7, 8, 9}};

    vector<map<string, pair<int, vector<int>>>> brain_melting_type = {
        {{"groupA", {100, {1, 2, 3}}}, {"groupB", {200, {4, 5}}}}, {{"groupC", {300, {9, 9, 9}}}}};

    pair<int, pair<string, double>> nested_pair = {1, {"nested", 2.718}};
    map<pair<int, int>, vector<string>> pair_key_map;
    pair_key_map[{1, 2}] = {"one", "two"};
    pair_key_map[{3, 4}] = {"three"};

    debug(my_list, my_deque);
    debug(my_uset, my_umap);
    debug(matrix2d);
    debug(nested_pair);
    debug(pair_key_map);
    debug(brain_melting_type);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}