#include <bits/stdc++.h>

class Solution {
    std::vector<std::pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void dfs(std::vector<std::vector<int>>& grid, int row, int col, int &area) {
        if (row < 0 or row >= grid.size() or col < 0 or col >= grid[0].size() or grid[row][col] != 1)
            return;
        
        grid[row][col] = 0;
        area++;
        
        for (auto [r, c] : dirs) {
            dfs(grid, row + r, col + c ,area);
        }
    }
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    int area = 0;
                    dfs(grid, i, j, area);
                    max_area = std::max(max_area, area);
                }
            }
        } 

        return max_area;
    }
};

