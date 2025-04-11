template <typename T = int>
struct Dsu2d {
    // MUST READ: Must use based-index 0 for modulo
    int n, row, col;
    vector<int> parent, size;

    Dsu2d() {};
    Dsu2d(int r, int c) {
        row = r, col = c;
        n = row * col;
        parent = vector<int>(n);
        size = vector<int>(n, 1);  // init size = 1
        for (int v = 0; v < n; v++) makeSet(v);
    }

    void makeSet(int r, int c) { makeSet(flat(r, c)); }

    pair<int, int> findSet(int r, int c) {
        int root = findSet(flat(r, c));
        return unFlat(root);
    }

    int flat(int r, int c) { return r * col + c; }

    pair<int, int> unFlat(int idx) {
        int r = idx / col;
        int c = idx % col;
        return {r, c};
    }

    bool unionSet(int r1, int c1, int r2, int c2) {
        int u = flat(r1, c1);
        int v = flat(r2, c2);
        return unionSet(u, v);
    }

    int getSize(pair<int, int> p) { return getSize(flat(p.first, p.second)); }

   private:
    void makeSet(int v) { parent[v] = v; }

    int findSet(int v) { return parent[v] = (v == parent[v] ? v : findSet(parent[v])); }

    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    int getSize(int v) { return size[findSet(v)]; }
};