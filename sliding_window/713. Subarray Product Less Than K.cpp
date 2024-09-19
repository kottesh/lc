class Solution {
public:
    // getting overflow error
    //int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    //    int count = 0;
    //    for (int win = 1; win <= nums.size(); win++) {
    //        int curr_win = win;

    //        long long prod = 1;
    //        for (int i = 0; i < curr_win; i++) {
    //            prod *= nums[i];
    //        }
    //        
    //        if (prod < k) count++;
    //        
    //        for (int i = curr_win; i < nums.size(); i++) {
    //            prod /= nums[i - curr_win];
    //            prod *= nums[i];

    //            if (prod < k) count++;
    //        }
    //    }    

    //    return count;
    //}

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        int count = 0;

        int left = 0,
            prod = 1;

        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];

            while (left <= right && prod >= k) {
                prod /= nums[left];
                left++;
            }
            
            count += (right - left + 1);
        }

        return count;
    }
};

