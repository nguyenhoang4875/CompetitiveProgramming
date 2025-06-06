#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

random_device rd;
mt19937 gen(rd());
int random(int l, int r) {
    uniform_int_distribution<int> dis(l, r);
    return dis(gen);
}

void genTest() {
    int a = random(1, 20);
    int b = random(1, 1e8);
    cout << a << " " << b << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    genTest();
    return 0;
}