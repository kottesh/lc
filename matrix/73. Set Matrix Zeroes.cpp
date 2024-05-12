#include <bits/stdc++.h>

class Solution {
    std::vector<std::vector<int>> locs;
public:
    // loc/locs ---> location / locations
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        for(int x = 0; x < m; x++)  {
            for(int y = 0; y < n; y++) {
                if(matrix[x][y] == 0)
                    locs.push_back({x, y});
            }
        }           

        for(const auto& loc : locs){
            for(int x = 0; x < n; x++)
                matrix[loc[0]][x] = 0;

            for(int y = 0; y < m; y++) 
                matrix[y][loc[1]] = 0;
        }
    }
};

int main() {
    std::vector<std::vector<int>> matrix {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    Solution ans;
    ans.setZeroes(matrix);

    for(const auto& row : matrix) {
        for(const auto& ele : row) {
            std::cout << ele << " ";
        }
        std::cout << "\n";
    }
}
