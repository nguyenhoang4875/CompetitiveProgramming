template <typename T = int>
struct BipartMatching {
    int N, M;  // N: số đỉnh bên trái, M: số đỉnh bên phải
    vector<vector<int>> adj;
    vector<int> seen, dist, matchL, matchR;
    int iteration;

    // Constructor
    BipartMatching(int leftNodes, int rightNodes) {
        N = leftNodes;
        M = rightNodes;
        adj.resize(N + 1);
        seen.resize(N + 1);
        dist.resize(N + 1);
        matchL.resize(N + 1);
        matchR.resize(M + 1);
        iteration = 0;
    }

    // Tìm kiếm đường tăng luồng bắt đầu từ u
    bool dfs(int u) {
        // Nếu đỉnh u đã được thăm trước đó, ta sẽ không thăm lại nữa
        if (seen[u] == iteration) return false;
        seen[u] = iteration;

        for (int v : adj[u]) {
            // Kiểm tra đỉnh v có phải là đỉnh tự do hay không
            if (matchR[v] == -1) {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }

        for (int v : adj[u]) {
            // Kiểm tra đỉnh đang được ghép với v có đi được từ đỉnh u không
            // và có cách nối khác từ đỉnh đang ghép với v không
            if (dist[matchR[v]] == dist[u] + 1 && dfs(matchR[v])) {
                // Ghi nhận cặp ghép (u, v) và thông báo có cách ghép từ đỉnh u
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }

        return false;
    }

    // Thêm cạnh từ đỉnh u (bên trái) tới đỉnh v (bên phải)
    void addEdge(int u, int v) { adj[u].push_back(v); }

    // Tính maximum matching
    int getMaxMatching() {
        // Trạng thái ban đầu chưa có cặp ghép
        fill(matchL.begin() + 1, matchL.begin() + N + 1, -1);
        fill(matchR.begin() + 1, matchR.begin() + M + 1, -1);

        int ans = 0;

        while (true) {
            // Xây dựng các đỉnh nguồn
            queue<int> q;
            for (int u = 1; u <= N; ++u) {
                if (matchL[u] == -1) {
                    dist[u] = 0;
                    q.push(u);
                } else {
                    dist[u] = -1;
                }
            }

            // Thuật toán loang (BFS)
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (matchR[v] != -1 && dist[matchR[v]] == -1) {
                        dist[matchR[v]] = dist[u] + 1;
                        q.push(matchR[v]);
                    }
                }
            }

            // Tìm đường tăng luồng
            int newMatches = 0;
            ++iteration;
            for (int u = 1; u <= N; ++u) {
                if (matchL[u] == -1) {
                    newMatches += dfs(u);
                }
            }

            if (newMatches == 0) break;
            // Cập nhật số lượng cặp ghép mới vào số cặp ghép hiện tại
            ans += newMatches;
        }

        return ans;
    }

    // Lấy kết quả matching (optional)
    vector<pair<int, int>> getMatching() {
        vector<pair<int, int>> result;
        for (int u = 1; u <= N; ++u) {
            if (matchL[u] != -1) {
                result.push_back({u, matchL[u]});
            }
        }
        return result;
    }
};
