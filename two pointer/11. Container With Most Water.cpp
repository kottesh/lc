class Solution {
public:
    int maxArea(std::vector<int>& height) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(nullptr);

        int left = 0, right = height.size() - 1;
        
        int max = INT_MIN;
        while (left < right) {
            max = std::max(max, (right - left) * std::min(height[left], height[right]));
            height[left] > height[right] ? right-- : left++;
        }

        return max;
    }
};

