class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        std::vector<int> res;
        
        int index;
        for (int &num : nums) {
            index = abs(num) - 1; 
            
            if (nums[index] < 0)
                res.push_back(abs(num));
            else 
                nums[index] *= -1;
        }

        return res;
    }

    //std::vector<int> findDuplicates(std::vector<int>& nums) {
    //    std::unordered_map<int, int> seen;
    //    
    //    std::vector<int> res;
    //    for (int &num : nums) {
    //        if (seen.find(num) != seen.end())
    //            res.push_back(num);
    //        else
    //            seen[num] = 1;
    //    }

    //    return res;
    //}
};
