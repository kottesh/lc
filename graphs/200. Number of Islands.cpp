#include <bits/stdc++.h>

class Solution {
private:
    void dfs(std::vector<std::vector<char>> &grid, int r, int c) {
        if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size() or grid[r][c] != '1')
            return;

        grid[r][c] = '0';

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int count = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j); 
                }
            }
        }

        return count;
    }
};

int main() {

    std::vector<std::vector<char>> grid = {
          {'1','1','0','0','0'},
          {'1','1','0','0','0'},
          {'0','0','1','0','0'},
          {'0','0','0','1','1'}
    };

    std::cout << (new Solution())->numIslands(grid);
}
