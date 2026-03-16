template <typename T = int>
struct Dsu2d {
    // MUST READ: Must use based-index 0 for modulo
    int n, row, col, num_set;
    vector<int> parent, siz;

    Dsu2d(int r, int c) {
        row = r;
        col = c;
        n = row * col;
        num_set = n;

        parent.resize(n);
        siz.assign(n, 1);

        iota(parent.begin(), parent.end(), 0);
    }
    inline int flat(int r, int c) const { return r * col + c; }
    inline pair<int, int> unFlat(int id) const { return {id / col, id % col}; }
    pair<int, int> findSet(int r, int c) { return unFlat(findRoot(flat(r, c))); }
    bool unionSet(int r1, int c1, int r2, int c2) { return unionSet(flat(r1, c1), flat(r2, c2)); }
    bool isSameSet(int r1, int c1, int r2, int c2) { return findRoot(flat(r1, c1)) == findRoot(flat(r2, c2)); }
    int getSize(int r, int c) { return getSize(flat(r, c)); }
    int getNumSet() const { return num_set; }
    bool inGrid (int r, int c) const { return 0 <= r and r < row and 0 <= c and c < col; }

   private:
    int findRoot(int v) { return parent[v] = (v == parent[v] ? v : findRoot(parent[v])); }
    bool unionSet(int a, int b) {
        a = findRoot(a);
        b = findRoot(b);

        if (a == b) return false;

        if (siz[a] < siz[b]) swap(a, b);

        parent[b] = a;
        siz[a] += siz[b];
        --num_set;

        return true;
    }
    int getSize(int v) { return siz[findRoot(v)]; }
};