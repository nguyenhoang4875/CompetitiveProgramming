#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> dp(N+1, vector<int>(M+1));
    dp[0][0] = 1;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i < N && j < M) {
                for (int k = j+1; k <= M; k++) {
                    dp[i+1][k] = (dp[i+1][k] + dp[i][j]) % MOD;
                }
                for (int k = i+1; k <= M; k++) {
                    dp[k][j+1] = (dp[k][j+1] + dp[i][j]) % MOD;
                }
            } else if (i >= N && j < M) {
                dp[i][j+1] = 0;
            } else if (j >= M && i < N) {
                dp[i+1][j] = 0;
            }
        }
    }
    
    cout << dp[N-1][M] << endl;
    
    return 0;
}
