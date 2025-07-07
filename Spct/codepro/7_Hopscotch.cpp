#include <bits/stdc++.h>
#define int long long

using namespace std;

int H, W, N;
int A[110][110];
int R[110][110];
int C[110][110];

/*
- update 8 hướng,
- Không có sourround thì làm như bản cũ
- Nếu có boom A[i][j] = 2 trên sourround thì thay hết hướng đó bằng V
*/

int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void Touch(int r, int c) {
    int V;

    if (A[r][c] == 0)
        V = 1;
    else
        V = 0;
    A[r][c] = V;

    for (int k = 0; k < 8; k++) {
        int nr = r;
        int nc = c;
        int flag = 0;
        int hasBoom = 0; // flag for Boom

        for (;;) {
            nr = nr + dr[k];
            nc = nc + dc[k];
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) break;
            if (A[nr][nc] == 2) {
                hasBoom = 1;
            }
            if (A[nr][nc] == V) {
                flag = 1;
                break;
            }
        }
        if (flag == 1 && !hasBoom) {
            nr = r;
            nc = c;
            for (;;) {
                nr = nr + dr[k];
                nc = nc + dc[k];
                if (A[nr][nc] == V) {
                    break;
                }
                A[nr][nc] = V;
            }
        }
        if (hasBoom && flag) {
            nr = r;
            nc = c;
            for (;;) {
                nr = nr + dr[k];
                nc = nc + dc[k];
                if (nr < 0 || nr >= H || nc < 0 || nc >= W) {
                    break;
                }
                A[nr][nc] = V;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}