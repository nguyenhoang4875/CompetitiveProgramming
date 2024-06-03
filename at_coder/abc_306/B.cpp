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
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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
int n;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    vector<int> res(num1.size() + num2.size(), 0);

    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
            res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            res[i + j] += res[i + j + 1] / 10;  // add carry
            res[i + j + 1] %= 10;               // take the modulo of 10
        }
    }

    int i = 0;
    string ans = "";
    while (res[i] == 0) i++;  // remove leading zero
    while (i < res.size()) ans += to_string(res[i++]);

    return ans;
}

string addStrings(string num1, string num2) {
    int l = num1.length() - 1;
    int l2 = num2.length() - 1;
    int x = 0;
    int carry = 0;
    string answer = "";

    while (l >= 0 || l2 >= 0 || carry > 0) {
        int digit1 = (l >= 0) ? num1[l] - '0' : 0;
        int digit2 = (l2 >= 0) ? num2[l2] - '0' : 0;
        x = digit1 + digit2 + carry;
        carry = x / 10;
        x = x % 10;

        answer = to_string(x) + answer;
        if (l >= 0) l--;
        if (l2 >= 0) l2--;
    }

    return answer;
}

void solve() {
    n = 63;
    int pt = 1;
    int x;
    int sum = 0;
    For(i, 0, 62) {
        cin >> x;
        x *= pt;
        pt *= 2;
        sum += x;
    }
    cin >> x;
    string b = "0";
    if (x == 1) {
        b = "9223372036854775808";
    }
    string ans = addStrings(to_string(sum), b);

    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}