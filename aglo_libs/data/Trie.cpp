template<int ms = 26, char FIRST = 'a'>
struct Trie {
    struct Node {
        Node* child[ms];
        int exist, cnt; // exist: exist string equals input string, cnt: number prefix of input string

        Node() {
            for (int i = 0; i < ms; i++) child[i] = NULL;
            exist = cnt = 0;
        }
    };

    int cur;
    Node* root;
    Trie() {
        cur = 0;
        root = new Node();
    };

    void add_string(string s) {
        Node* p = root;
        for (auto f : s) {
            int c = f - FIRST;
            if (p->child[c] == NULL) p->child[c] = new Node();

            p = p->child[c];
            p->cnt++;
        }
        p->exist++;
    }

    bool delete_string_recursive(Node* p, string& s, int i) {
        if (i != (int)s.size()) {
            int c = s[i] - FIRST;
            bool isChildDeleted = delete_string_recursive(p->child[c], s, i + 1);
            if (isChildDeleted) p->child[c] = NULL;
        }
        else p->exist--;

        if (p != root) {
            p->cnt--;
            if (p->cnt == 0) {
                delete(p);
                return true;
            }
        }
        return false;
    }

    void delete_string(string s) {
        if (find_string(s) == false) return;

        delete_string_recursive(root, s, 0);
    }

    bool find_string(string s) {
        Node* p = root;
        for (auto f : s) {
            int c = f - FIRST;
            if (p->child[c] == NULL) return false;
            p = p->child[c];
        }
        return (p->exist != 0);
    }

    int count_prefix(string s) {
        Node* p = root;
        for (auto f : s) {
            int c = f - FIRST;
            if (p->child[c] == NULL) return 0;
            p = p->child[c];
        }
        return p->cnt;
    }
};