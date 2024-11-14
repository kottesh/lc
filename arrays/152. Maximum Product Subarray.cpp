class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int res = INT_MIN; 

        int _prod = nums[0];
        
        for (auto it = nums.begin() + 1; it != nums.end(); ++it) {
            int num = *it;
            _prod *= num;
            if (_prod < 0)
                _prod = 1;
            res = std::max(_prod, res);
        }

        return res;
    }
};
