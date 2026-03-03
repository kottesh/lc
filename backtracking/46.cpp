class Solution {
    void findPermutes(vector<vector<int>>& ans, const vector<int>& nums, vector<int>& curr, vector<bool> taken) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!taken[i]) {
                taken[i] = true;
                curr.push_back(nums[i]);
                findPermutes(ans, nums, curr, taken);
                taken[i] = false;
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;   
        vector<bool> taken(nums.size()); 
        vector<int> curr;
        
        findPermutes(res, nums, curr, taken);

        return res;
    }
};


