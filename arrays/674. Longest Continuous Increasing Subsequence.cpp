#include <bits/stdc++.h>

class Solution {
public:
    int findLengthOfLCIS(const std::vector<int>& arr) {
        int n = arr.size();
        int len = INT_MIN;

        if (n == 1) return 1;
        
        int l_len = 1;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] < arr[i+1]) l_len++; 
            else l_len = 1;
            len = std::max(len, l_len);
        }

        return len;
    }
};

int main() {
    std::cout << (new Solution())->findLengthOfLCIS(std::vector<int> {1,3,5, 4, 7});
}

