#include<bits/stdc++.h>
using namespace std;

/**
 * The problem: https://leetcode.com/problems/sudoku-solver/description/
 * Solution: https://www.youtube.com/watch?v=SprpWBHgkOI
*/


class Solution {
public:

    void checkSquare3x3() {
        int x = 7, y = 6;
        for(int i = 0; i < 9 ; i++) {
            int nr = x / 3 * 3 + i / 3;
            int nc = y / 3 * 3 + i % 3;
            cout << "nr = " << nr << " nc = " << nc << endl;
        } 
    }
    void printMatrix(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i = 0; i < 9; i++){
            // check row 
            if(board[i][col] == ch) return false;

            // check column
            if(board[row][i] == ch) return false;

            // for sub grid (square 3 x 3)
            int nr = 3 * (row/3) + i / 3;
            int nc = 3 * (col/3) + i % 3;
            if(board[nr][nc] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        int n = 9;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.'){
                    for(char ch='1'; ch <= '9'; ch++){
                        if(isValid(board, i, j, ch)){
                            board[i][j] = ch;
                            if(solve(board)) return true; // if it's okay
                            else board[i][j] = '.'; // Otherwise go back 
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
   vector<vector<char>> board = 
   {{'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};
//    vector<vector<char>> board = 
//    {{'.','.','.','.','.','.','.','.','.'},
//     {'.','.','.','.','.','.','.','.','.'},
//     {'.','.','.','.','.','.','.','.','.'},
//     {'.','.','.','.','.','.','.','.','.'},
//     {'.','.','.','.','.','.','.','.','.'},
//     {'.','.','.','.','.','.','.','.','.'},
//     {'.','.','.','.','.','.','.','.','.'},
//     {'.','.','.','.','.','.','.','.','.'},
//     {'.','.','.','.','.','.','.','.','.'}}; 
    Solution s;
    s.solveSudoku(board);
    s.printMatrix(board);

    // vector<vector<int>> a(4, vector<int>(6));
    // cout << a[3][5];
   
}