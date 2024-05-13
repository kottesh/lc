#include <bits/stdc++.h>

class Solution {
public:
    int matrixScore(std::vector<std::vector<int>>& grid) {
        for (std::vector<int> &row:grid) {
            if (row[0] == 0) {
                for (int &val : row) {
                    val = (val == 0) ? 1 : 0;
                }
            }
        }

        int row_size = grid.size();
        int col_size = grid[0].size();
        
        for (int x = 0; x < col_size; x++) {
            int count = 0; // tracks number of zeros in the currently iterating column
            for (int y = 0; y < row_size; y++) {
                if (grid[y][x] == 0) count++;
            }
            if (count > (row_size - count)) {
                for (int idx = 0; idx < row_size; idx++) {
                    grid[idx][x] = (grid[idx][x] == 0) ? 1 : 0;
                }
            }
        }

        int score = 0;
        for (int i = 0; i < row_size; i++) {
            int curr = 0;
            for (int j = 0; j < col_size; j++) {
                if (grid[i][j]) {
                    curr += grid[i][j] * std::pow(2, col_size - (1 + j)); // could use bit shifting(towards left) here with 1 like 1 << (col_size - (j + 1)) and do OR operation.
                }
            }
            score += curr;
        }

        return score;
    }
};


int main() {
    std::vector<std::vector<int>> nums {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    std::cout << (new Solution())->matrixScore(nums) << std::endl;
}