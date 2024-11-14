class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int len = nums.size();

        std::vector<int> prefix(len);
        std::vector<int> suffix(len);

        prefix[0] = 1;
        suffix[len-1] = 1;

        for (int i = 1; i < len; i++) {
            prefix[i] = prefix[i-1] * nums[i];
            suffix[len - i - 1] = suffix[len - i] * nums[len - i];
        }

        std::vector<int> res(len);

        for (int i = 0; i < len; i++) {
            res[i] = prefix[i] * suffix[i]; 
        }

        return res;
    }
};
