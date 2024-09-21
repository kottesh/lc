class Solution {
public:
    std::unordered_map<int, int> store;
    int majorityElement(std::vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        for (const auto & num : nums) {
            if (store.find(num) == store.end())
                store[num] = 1;
            else
                store[num]++;
        } 
        
        int ele;
        for (auto item : store) {
            if (item.second > nums.size() / 2)
                ele = item.first;
        }

        return ele;
    }
};
