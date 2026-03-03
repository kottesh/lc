class Solution {
    void findPowerset(vector<vector<int>>& res, const vector<int>& nums, vector<int>& curr, int start = 0) {
        res.push_back(curr);

        if (curr.size() == nums.size())
            return;

        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            findPowerset(res, nums, curr, i + 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        findPowerset(res, nums, curr);

        return res;
    }
};
