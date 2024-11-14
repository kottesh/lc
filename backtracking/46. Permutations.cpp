class Solution {
private:
    void compute_combinations(const auto &nums, auto &taken, auto &res, auto &i_nums) {
        if (i_nums.size() == nums.size()) {
            res.push_back(i_nums);
            return;
        } 

        for (int i = 0; i < nums.size(); i++) {
            if (!taken[i]) {
                i_nums.push_back(nums[i]);
                taken[i] = !taken[i];
                compute_combinations(nums, taken, res, i_nums);
                taken[i] = !taken[i];
                i_nums.pop_back();
            }
        }
    }
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        std::vector<std::vector<int>> res;
        std::vector<bool> taken(nums.size(), false);
        std::vector<int> i_nums;
        compute_combinations(nums, taken, res, i_nums);
        return res;
    }
};

