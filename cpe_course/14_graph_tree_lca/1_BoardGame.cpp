#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Give a list of words.
 * Given n x m board where every cell has one character.
 * Find all possible words that are part of the list and can be
 * formed by a sequence of adjacent characters from board.
 * Note that we can move to any of 8 adjacent characters,
 * but a word should not have multiple instant of same cell:
 *
 * Example:
 *  words = {snake, for, quez, snack, snacks, sens, tunes, cat}
 *  n = 3, m = 4
 *  sert
 *  unks
 *  tcat
 *
 * => ans = {cat, snack, snacks, tunes, snake}
 *
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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int t, n, m;
char a[105][105];
set<string> words;
set<string> ans;

struct Node {
    char s;
    unordered_map<char, Node*> children;
    string word;
    bool isTerminal;

    Node(char s) {
        this->s = s;
        isTerminal = false;
        word = "";
    }
};

struct Trie {
    Node* root;

    Trie() { root = new Node('\0'); }

    void addWord(string word) {
        Node* temp = root;
        for (auto ch : word) {
            if (temp->children.count(ch) == 0) {
                temp->children[ch] = new Node(ch);
            }
            temp = temp->children[ch];
        }
        // last node
        temp->isTerminal = true;
        temp->word = word;
    }
};

bool inBound(int r, int c) {
    if (r < 1 or r > n or c < 1 or c > m) return false;
    return true;
}

void dfs(Node* node, int i, int j, vvb& visited, unordered_set<string>& ans) {
    // base case
    char ch = a[i][j];
    if (node->children.count(ch) == 0) {
        return;
    }

    // otherwise trie contains this node
    visited[i][j] = true;
    node = node->children[ch];

    // if it is a terminal node in the trie
    if (node->isTerminal) {
        ans.insert(node->word);
    }
    For(dx, -1, 1) {
        For(dy, -1, 1) {
            if (dx == 0 and dy == 0) continue;
            int ni = i + dx;
            int nj = j + dy;
            if (!inBound(ni, nj) or visited[ni][nj]) continue;
            // if it is in bound and is not visited
            dfs(node, ni, nj, visited, ans);
        }
    }
    // last step (backtracking)
    visited[i][j] = false;
    return;
}

void solve() {
    cin >> t;
    For(i, 1, t) {
        string s;
        cin >> s;
        words.insert(s);
    }

    cin >> n >> m;
    For(i, 1, n) {
        For(j, 1, m) { cin >> a[i][j]; }
    }

    // 1. Trie
    Trie t;
    for (auto w : words) {
        t.addWord(w);
    }
    cout << el;

    // 2. Take a container to store words that are found in dfs search
    unordered_set<string> ans;

    // 3. Step(8-DFS Search for every cell)
    vvb visited(n + 1, vb(m + 1, false));

    For(i, 1, n) {
        For(j, 1, m) { dfs(t.root, i, j, visited, ans); }
    }

    // 4. Print output
    cout << ans.size() << el;
    for (auto w : ans) cout << w << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}