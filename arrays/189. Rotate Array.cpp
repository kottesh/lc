class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
    //void rotate(std::vector<int>& nums, int k) {
    //    std::vector<int> res(nums.size());
    //        
    //    int start= 0;
    //    for (int i = k; i < nums.size(); i++) {
    //        res[i] = nums[start++];
    //    }

    //    for (int i = 0; i < k; i++) {
    //        res[i] = nums[start++];
    //    }

    //    nums = res;
    //}
};
