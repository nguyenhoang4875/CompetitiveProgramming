#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 2005;

int f[MAXN][MAXN];

int count_scenarios(int N, int M) {
    for(int i = 1; i <= N; i++) f[i][0] = 0;
    for(int j = 0; j <= M; j++) f[0][j] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            f[i][j] = (f[i-1][j-1] + f[i][j-1]) % MOD;
        }
    }
    return f[N][M];
}

int main() {
    int tcs;
    cin >> tcs;
    while (tcs--) {
        int N, M;
        cin >> N >> M;
        cout << count_scenarios(N, M) << endl;
    }
    
    return 0;
}
