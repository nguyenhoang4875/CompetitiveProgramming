#include <bits/stdc++.h>
#define int long long
/*
You are given a sequence of n words, where the i‑th word has length wᵢ, and a maximum line width L.
You must arrange the words in order into lines so that each line contains one or more consecutive
words separated by exactly one space, and the total of the word lengths plus those spaces never
exceeds L. After fitting words on a line, any unused space at the end contributes a “cost” equal to
the cube of its size; Your goal is to choose line breaks that minimize the sum of all lines’ costs.

Your program should read the integers n and L, followed by the n word‑lengths w₁…wₙ, then output the
smallest possible total cost and print words for each line.

Input:
n L
w1 w2 ... wn

output:
maxCost
number lines:(m)
word in line 1
...
words in line m

Example:
Input:
6 12
3 2 5 7 2 2

Output:
468
3
1 3
4 4
5 6

*/

using namespace std;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n, L;
    cin >> n >> L;

    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) { cin >> w[i]; }

    vector<int> f(n + 1, oo);    // f[i] = min cost for first i-th words: 1...i
    vector<int> par(n + 1, -1);  // parent for trace back

    f[0] = 0;  // basecase
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int k = 1; k <= i; k++) {
            sum += w[i - k + 1];
            int spaces = k - 1;
            if (sum + spaces > L) break;

            int len = L - (sum + spaces);  // unused len
            int cost = len * len * len;

            if (f[i - k] + cost < f[i]) {
                f[i] = f[i - k] + cost;
                par[i] = i - k;
            }
        }
    }

    vector<pair<int, int>> lines;
    for (int cur = n; cur > 0; cur = par[cur]) { lines.push_back({par[cur] + 1, cur}); }
    reverse(lines.begin(), lines.end());
    // minCost;
    cout << f[n] << '\n';
    // lines
    cout << lines.size() << '\n';
    for (auto &[f, s] : lines) { cout << f << " " << s << '\n'; }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}