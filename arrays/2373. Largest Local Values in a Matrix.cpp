#include <bits/stdc++.h>

class Solution {
    int find_max_val(std::vector<std::vector<int>>& grid, int x_i, int y_i) {
        int max_val = 0;
        int x_e = x_i + 3;
        int y_e = y_i + 3;

        for (int i = x_i; i < x_e; i++) {
            for (int j = y_i; j < y_e; j++) {
                max_val = std::max(max_val, grid[i][j]);
            }
        }
        return max_val;
    }
public:
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
        int size = grid.size() - 2;
        std::vector<std::vector<int>> max_local(size, std::vector<int>(size));   

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                max_local[i][j] = find_max_val(grid, i, j);
            }
        }
        return max_local;
    }
};

int main() {
    std::vector<std::vector<int>> input = {{9,9,8,1}, {5,6,2,6}, {8,2,6,4}, {6,2,2,2}};
    std::vector<std::vector<int>> ans = (new Solution())->largestLocal(input);

    for (auto row : ans) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
