#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        component.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

string canRearrangeToTarget(int N, int M, vector<int>& first_queue, vector<int>& second_queue, vector<pair<int, int>>& swaps) {
    // Create adjacency list for the graph
    vector<vector<int>> graph(N);
    
    for (auto& swap : swaps) {
        int x = swap.first - 1;  // Convert to 0-based index
        int y = swap.second - 1; // Convert to 0-based index
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<bool> visited(N, false);
    
    // Traverse each component
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            vector<int> component;
            bfs(i, graph, visited, component);

            // Gather elements from the component in both queues
            vector<int> first_part, second_part;
            for (int idx : component) {
                first_part.push_back(first_queue[idx]);
                second_part.push_back(second_queue[idx]);
            }

            // Sort and compare
            sort(first_part.begin(), first_part.end());
            sort(second_part.begin(), second_part.end());
            if (first_part != second_part) {
                return "NO";
            }
        }
    }

    return "YES";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> first_queue(N);
        vector<int> second_queue(N);

        for (int i = 0; i < N; i++) {
            cin >> first_queue[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> second_queue[i];
        }

        vector<pair<int, int>> swaps(M);
        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            swaps[i] = {x, y};
        }

        cout << canRearrangeToTarget(N, M, first_queue, second_queue, swaps) << endl;
    }

    return 0;
}
