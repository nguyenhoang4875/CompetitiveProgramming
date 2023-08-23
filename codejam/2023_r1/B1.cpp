#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int R, C, K;
string S;
vector<vector<int>> switches;

int countConfigurations(int row, int col, vector<vector<int>>& grid) {
    if (row == R) {
        // Base case: all particles have been detected with positive charge
        return 1;
    }

    int nextRow = col == C - 1 ? row + 1 : row;
    int nextCol = col == C - 1 ? 0 : col + 1;

    // Case 1: no switch is installed in this cell
    int ans = countConfigurations(nextRow, nextCol, grid);

    // Case 2: horizontal switch starting from this cell
    if (col < C - 1 && grid[row][col] == 0 && grid[row][col + 1] == 0) {
        grid[row][col] = grid[row][col + 1] = 1;
        ans = (ans + countConfigurations(nextRow, nextCol, grid)) % MOD;
        grid[row][col] = grid[row][col + 1] = 0;
    }

    // Case 3: vertical switch starting from this cell
    if (row < R - 1 && grid[row][col] == 0 && grid[row + 1][col] == 0) {
        grid[row][col] = grid[row + 1][col] = 1;
        ans = (ans + countConfigurations(nextRow, nextCol, grid)) % MOD;
        grid[row][col] = grid[row + 1][col] = 0;
    }

    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> R >> C >> K >> S;

        // Initialize the grid and particles
        vector<vector<int>> grid(R, vector<int>(C));
        vector<int> particles(C);
        for (int i = 0; i < C; i++) {
            particles[i] = S[i] == '+' ? 1 : -1;
        }
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            grid[x - 1][y - 1] = 1;
            if (y < C) {
                particles[y] *= -1;
            }
        }

        // Flip the charges of particles passing through the pre-installed switches
        for (auto& s : switches) {
            int row = s[0], col = s[1];
            if (col < C - 1 && grid[row][col] == 0 && grid[row][col + 1] == 0) {
                particles[col] *= -1;
            }
            if (row < R - 1 && grid[row][col] == 0 && grid[row + 1][col] == 0) {
                particles[col] *= -1;
            }
        }

        // Count the number of valid configurations of 1x2 switches
        int ans = countConfigurations(0, 0, grid);

        cout << ans << endl;
    }

    return 0;
}
