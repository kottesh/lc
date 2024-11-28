#include <bits/stdc++.h>



int main() {
    std::vector<std::vector<int>> grid = {
        {0,1,1},
        {1,1,0},
        {1,1,0}
    };

    std::cout << (new Solution())->minimumObstacles(grid);
}
