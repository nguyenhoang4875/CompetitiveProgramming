#include<bits/stdc++.h>

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
#define int long long
#define pb push_back
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//

int n, m;
int a[105][15];
bool visited[105][105];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};
bool touch = false;


bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

bool touchBound(int r, int c) {
    if(r == 1|| r == n || c == 1 || c== m) return true;
    return false;
}

void dfs(int r, int c) {
    if(!inBound(r, c) || visited[r][c] || a[r][c] == 1) return;
    visited[r][c] = true;
    if(touchBound(r, c) && !touch) touch = true;
    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
}

void solve() {
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            if(!visited[r][c] && a[r][c] == 0) {
                touch = false;
                dfs(r, c);
                if(!touch) cnt++;
            }
        }
    }
    cout << cnt << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}