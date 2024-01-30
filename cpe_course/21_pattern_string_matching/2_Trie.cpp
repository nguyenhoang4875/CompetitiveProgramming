#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Search a string
 * Solution: Using trie
 *
 * TC: O(n)
 * MC: O(n)
 */

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

struct Node {
    Node *next[26];

    Node() {
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

Node *root;

void insert(string s) {
    Node *cur = root;

    for (auto c : s) {
        int idx = c - 'a';

        // new node
        if (cur->next[idx] == NULL) {
            cur->next[idx] = new Node();
        }
        // go to that node
        cur = cur->next[idx];
    }
}

bool search(string s) {
    Node *cur = root;

    for (auto c : s) {
        int idx = c - 'a';

        if (cur->next[idx] == NULL) {
            return false;
        }
        cur = cur->next[idx];
    }

    return true;
}

void solve() {
    string s, p;
    cin >> s >> p;
    root = new Node();
    int n = s.size(), m = p.size();
    for (int i = 0; i + m <= n; i++) {
        insert(s.substr(i));
    }
    if (search(p)) {
        cout << "Found" << el;
    } else {
        cout << "Not found" << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}