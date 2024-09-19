class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        //transpose
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = row + 1; col < matrix[row].size(); col++) {
                std::swap(matrix[row][col], matrix[col][row]);
            }
        }
        
        for (auto &row : matrix) {
            std::reverse(row.begin(), row.end());
        }
        
        for (const auto& row : matrix) {
            for (const int val : row) {
                std::cout << val << " ";
            } 
            std::cout << "\n";
        }
    }
};

