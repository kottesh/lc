#include <bits/stdc++.h>

class Solution {
    void dfs(std::vector<std::vector<char>>& board, int r, int c) {
        if (r <= 0 or r >= board.size() - 1 or c <= 0 or c >= board[0].size() - 1 or board[r][c] == 'X')
            return;
        
        board[r][c] = 'X';
        
        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
public:
    void solve(std::vector<std::vector<char>>& board) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == 'O') {
                    dfs(board, r, c);
                }
            }
        }
    }
};

int main() {
    //std::vector<std::vector<char>> grid = {
    //    {'X','X','X','X'},
    //    {'X','O','O','X'},
    //    {'X','X','O','X'},
    //    {'X','O','X','X'}
    //};
    std::vector<std::vector<char>> grid = {{'X'}};

    (new Solution())->solve(grid);

    for (auto row : grid) {
        for (auto col : row) {
            std::cout << col << " ";
        }
        std::cout << "\n";
    }
}
