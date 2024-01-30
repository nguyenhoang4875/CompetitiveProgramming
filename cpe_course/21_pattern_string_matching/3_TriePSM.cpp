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
    bool isEnd;

    Node() {
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
        isEnd = false;
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

    // set end node
    cur->isEnd = true;
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

    return cur->isEnd;
}

void solve() {
    int n;
    cin >> n;
    root = new Node();
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        insert(tmp);
    }

    string pattern;
    cin >> pattern;
    if (search(pattern)) {
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