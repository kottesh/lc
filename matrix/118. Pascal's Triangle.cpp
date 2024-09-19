class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> res {{1}}; 
        
        for (int i = 1; i < numRows; i++) {
            std::vector<int> row;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.push_back(1);
                    continue;
                }
                row.push_back(res[i-1][j] + res[i-1][j-1]);
            }
            res.push_back(row);
        }

        for (auto &row : res) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }

        return res;
    }
};

