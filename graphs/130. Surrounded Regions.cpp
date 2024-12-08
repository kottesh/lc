#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int r, int c) {
        if (r < 0 or r >= board.size() or c < 0 or c >= board[0].size() or visited[r][c] == 1 or board[r][c] == 'X')
            return;
        
        visited[r][c] = 1;
        
        for (auto [dr, dc] : dirs)
            dfs(board, visited, r + dr, c + dc);
    }
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), -1));
        
        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O')
                dfs(board, visited, 0, i);
            if (board[board.size() - 1][i] == 'O')
                dfs(board, visited, board.size() - 1, i);
        }

        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O')
                dfs(board, visited, i, 0);
            if (board[i][board[0].size() - 1] == 'O')
                dfs(board, visited, i, board[0].size() - 1);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (visited[i][j] == -1 and board[i][j] != 'X')
                    board[i][j] = 'X';
            }
        }
    }
};

int main() {
    //vector<vector<char>> grid = {
    //    {'X','X','X','X'},
    //    {'X','O','O','X'},
    //    {'X','X','O','X'},
    //    {'X','O','X','X'}
    //};
    vector<vector<char>> grid = {{'X'}};

    (new Solution())->solve(grid);

    for (auto row : grid) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << "\n";
    }
}
