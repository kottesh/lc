#include <stdio.h>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            int mid_val = matrix[mid / n][mid % n];

            if (mid_val == target) return true;
            else if (mid_val > target) r = mid - 1;
            else l = mid + 1;
        }

        return false;
    }
};

