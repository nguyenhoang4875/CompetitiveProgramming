#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Cấu trúc truy vấn Offline
struct Query {
    int id;
    int s, t, w;
};

// Cấu trúc lưu đỉnh để sắp xếp
struct Node {
    int u, w;
    bool operator<(const Node& other) const {
        return w > other.w;
    }
};

int N, M, Q;
vector<int> A;
vector<vector<int>> adj;

// Tarjan & Block-Cut Tree
int timer_tarjan = 0, bct_nodes = 0;
vector<int> dfn, low, stk;
vector<vector<int>> bct;

void dfs_tarjan(int u, int p = 0) {
    dfn[u] = low[u] = ++timer_tarjan;
    stk.push_back(u);

    for (int v : adj[u]) {
        if (v == p) {
            p = 0;  // Xử lý đa đồ thị (nhiều cạnh giữa u và p)
            continue;
        }
        if (dfn[v]) {
            low[u] = min(low[u], dfn[v]);
        } else {
            dfs_tarjan(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] >= dfn[u]) {
                bct_nodes++;
                bct[u].push_back(bct_nodes);
                bct[bct_nodes].push_back(u);

                while (true) {
                    int x = stk.back();
                    stk.pop_back();
                    bct[x].push_back(bct_nodes);
                    bct[bct_nodes].push_back(x);
                    if (x == v) break;
                }
            }
        }
    }
}

// Euler Tour & LCA (Binary Lifting)
int timer_bct = 0, logN = 0;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs_bct(int u, int p) {
    tin[u] = ++timer_bct;
    up[u][0] = p;
    for (int i = 1; i <= logN; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (int v : bct[u]) {
        if (v != p) dfs_bct(v, u);
    }
    tout[u] = timer_bct;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int get_lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = logN; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

// Fenwick Tree (BIT) hiệu năng cao
struct Fenwick {
    int n;
    vector<long long> tree;
    Fenwick(int n) : n(n), tree(n + 2, 0) {
    }

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    A.resize(N + 1);
    vector<Node> nodes(N);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        nodes[i - 1] = {i, A[i]};
    }

    adj.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Khởi tạo Tarjan BCT
    dfn.assign(N + 1, 0);
    low.assign(N + 1, 0);
    bct_nodes = N;
    bct.resize(2 * N + 1);

    for (int i = 1; i <= N; ++i) {
        if (!dfn[i]) {
            dfs_tarjan(i);
            stk.clear();
        }
    }

    // Tiền xử lý LCA
    while ((1 << logN) <= bct_nodes) logN++;
    tin.assign(bct_nodes + 1, 0);
    tout.assign(bct_nodes + 1, 0);
    up.assign(bct_nodes + 1, vector<int>(logN + 1, 0));

    for (int i = 1; i <= bct_nodes; ++i) {
        if (!tin[i] && i <= N) {
            dfs_bct(i, i);
        }
    }

    // Đọc và sắp xếp các câu truy vấn
    cin >> Q;
    vector<Query> queries(Q);
    for (int i = 0; i < Q; ++i) {
        queries[i].id = i;
        cin >> queries[i].s >> queries[i].t >> queries[i].w;
    }

    sort(queries.begin(), queries.end(), [](const Query& a, const Query& b) {
        return a.w > b.w;
    });
    sort(nodes.begin(), nodes.end());

    // Tính toán Offline bằng BIT
    Fenwick bit(timer_bct);
    vector<long long> ans(Q);
    int node_ptr = 0;

    for (const auto& q : queries) {
        while (node_ptr < N && nodes[node_ptr].w >= q.w) {
            int u = nodes[node_ptr].u;
            bit.add(tin[u], A[u]);
            bit.add(tout[u] + 1, -A[u]);
            node_ptr++;
        }

        int lca = get_lca(q.s, q.t);
        long long sum_s = bit.query(tin[q.s]);
        long long sum_t = bit.query(tin[q.t]);
        long long sum_lca = bit.query(tin[lca]);

        int p_lca = (up[lca][0] == lca) ? 0 : up[lca][0];
        long long sum_p_lca = (p_lca == 0) ? 0 : bit.query(tin[p_lca]);

        ans[q.id] = sum_s + sum_t - sum_lca - sum_p_lca;
    }

    for (int i = 0; i < Q; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}