#include <bits/stdc++.h>
class Solution {
private:
    int countLives(std::vector<std::vector<int>> & board, int i, int j, int m, int n) {
        return (
                ((i-1 < 0) ? 0 : board[i-1][j]) + ((i+1 >= m) ? 0 : board[i+1][j]) + 
                ((j-1 < 0) ? 0 : board[i][j-1]) + ((j+1 >= n) ? 0 : board[i][j+1]) +
                ((i-1 < 0 || j - 1 < 0) ? 0 : board[i-1][j-1]) + ((i+1 >= m || j + 1 >= n) ? 0 :board[i+1][j+1]) +
                ((i-1 < 0 || j + 1 >= n ) ? 0 : board[i-1][j+1]) + ((i+1 >= m || j - 1 < 0) ? 0 :board[i+1][j-1])
        );
    }
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr); std::cout.tie(nullptr);
        std::vector<std::vector<int>> res(board.size(), std::vector<int>(board[0].size(), 0));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int count = countLives(board, i, j, board.size(), board[0].size());
                std::cout << "(" << i << ", " << j << ") -> " << count << std::endl;
                if (board[i][j]) {
                    if (count < 2) res[i][j] = 0;
                    else if (count == 2 || count == 3) res[i][j] = 1;
                    else if (count > 3) res[i][j] = 0;
                    else res[i][j] = board[i][j];
                } else {
                    if (count == 3)
                        res[i][j] = 1;
                    else
                        res[i][j] = board[i][j];
                } 
            }
        } 
        
        board = res;
    }
};

int main() {
    std::vector<std::vector<int>> a = {
        {0,1,0},{0,0,1},{1,1,1},{0,0,0}
    };

    (new Solution())->gameOfLife(a);
}

