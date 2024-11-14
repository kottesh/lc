class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        int len = arr.size();
        std::vector<std::pair<int, int>> nums(len);
        std::vector<int> res(len);

        for (int i = 0; i < len; i++)
            nums[i] = {arr[i], i};

        std::sort(nums.begin(), nums.end());
            
        int rank = 1;
        for (int i = 0; i < len; i++) {
            if (i == 0 || nums[i].first == nums[i-1].first) {
                res[nums[i].second] = rank;
            } else {
                res[nums[i].second] = ++rank;
            }
        }

        return res;
    }
};
