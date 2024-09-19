class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::vector<std::string> s_nums; 
        std::string res;

        for (const auto & val : nums)
            s_nums.push_back(to_string(val));
        
        sort(
            s_nums.begin(),
            s_nums.end(), 
            [](const std::string &a, const std::string &b){
                return a+b > b+a;
            }
        );


        //bubble sort just for testing to check if I understand this sorting condition. 
        //for (int i = 0; i < s_nums.size() - 1; i++) {
        //    for (int j = 0; j < s_nums.size() - i - 1; j++) {
        //        if (s_nums[j]+s_nums[j+1] < s_nums[j+1] + s_nums[j])
        //            std::swap(nums[j], nums[j+1]);
        //    }
        //}

        for (const auto num : s_nums)
            res += num;

        if (res[0] == '0') return "0";

        return res;
    }
};
