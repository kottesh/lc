#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> lexicalOrder(int n) {
        std::vector<int> res;
            
        int curr = 1;
        for (int i = 1; i <= n; i++) {
            res.push_back(curr);
            
            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                while (curr % 10 == 9 || curr > n) {
                    curr /= 10;
                }
                curr += 1;
            }
        }

        for (auto val : res) {
            std::cout << val << ", ";
        }

        return res;
    }
    //std::vector<int> lexicalOrder(int n) {
    //    std::vector<std::string> nums; 

    //    for (int i = 1; i <= n; i++) nums.push_back(to_string(i));

    //    sort(nums.begin(), nums.end());
    //    
    //    std::vector<int> res;
    //    for (auto item : nums) res.push_back(stoi(item));

    //    return res;
    //}
};

int main() {
   (new Solution())->lexicalOrder(120);
}
