#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> ans;

        int noElements = matrix[0].size() * matrix.size();
        int top = 0, left = 0;
        int bottom = matrix.size() - 1, right = matrix[0].size() - 1;

        while(ans.size() != noElements) {
            for(int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            if(ans.size() == noElements)
                break;

            for(int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(ans.size() == noElements)
                break;

            for(int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            if(ans.size() == noElements)
                break;

            for(int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};

int main() {
    std::vector<std::vector<int>> matrix {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    };

    Solution ans;
    std::vector<int> res (ans.spiralOrder(matrix));

    for(int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl; 
    }
}