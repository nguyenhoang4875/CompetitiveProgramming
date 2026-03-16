template <typename T = int>
struct Dsu {
    // MUST READ: Works for both base-index: 0 and 1
    int n, num_set;
    vector<int> parent, siz;

    Dsu(int _n) {
        n = _n;
        num_set = n;
        parent.resize(n + 1);
        siz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findSet(int v) { return parent[v] = (v == parent[v] ? v : findSet(parent[v])); }
    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);

        if (a == b) return false;
        if (siz[a] < siz[b]) swap(a, b);  // set a is root of the bigger size of tree
        parent[b] = a;
        siz[a] += siz[b];
        --num_set;
        return true;
    }
    int getSize(int v) { return siz[findSet(v)]; }
    bool isSameSet(int u, int v) { return findSet(u) == findSet(v); }
    int getNumSet() const { return num_set; }
};