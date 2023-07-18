#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;

void printBoard(int n, int board[][20]) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << '\n';
}

bool canPlace(int board[][20], int n, int x, int y) {
    // column
    for(int k = 1; k <= x; k++) {
        if(board[k][y] == 1) return false;
    }

    // Left Diag
    int i = x;
    int j = y;
    while(i >= 1 && j >= 1) {
        if(board[i][j]) return false;
        i--; j--;
    }

    // Right Diag
    i = x;
    j = y;
    while(i >= 1 && j <= n) {
        if(board[i][j]) return false;
        i--; j++;
    }
    return true;
}

bool nQueen(int n, int i, int board[][20]) {
    // base case
    if(i == n + 1) {
        printBoard(n, board);
        return true;
    }

    // rec case
    // try to place queen in every row
    for(int j = 1; j <= n; j++) {
        if(!canPlace(board, n, i, j)) continue; // continue if can not place
        // whether the current i, j is safe or not
        board[i][j] = 1;
        bool success = nQueen(n, i + 1, board);
        if(success) return true;
        board[i][j] = false;
    }
    return false;

}

void solve() {
    int n;
    int board[20][20] = {0};
    cin >> n;

    nQueen(n, 1, board);

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}