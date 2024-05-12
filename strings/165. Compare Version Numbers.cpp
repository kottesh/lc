#include <bits/stdc++.h>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        std::vector<int> nums_x;
        std::vector<int> nums_y;

        std::string temp;

        std::stringstream ss(version1);
        while (std::getline(ss, temp, '.')) {
            nums_x.push_back(std::stoi(temp)); 
        }

        ss.str("");
        ss.clear();
        ss << version2;

        while (std::getline(ss, temp, '.')) {
            nums_y.push_back(std::stoi(temp));
        }

        for (int i = 0; i < std::max(nums_x.size(), nums_y.size()); i++) {
            int num1 = (i >= nums_x.size()) ? 0 : nums_x[i];
            int num2 = (i >= nums_y.size()) ? 0 : nums_y[i];
            
            if (num1 > num2) return 1; 
            else if (num1 < num2) return -1;
        }

        return 0;
    }
};

int main () {
    std::cout << (new Solution())->compareVersion("7.5.2.4", "7.5.3") << std::endl;
}
