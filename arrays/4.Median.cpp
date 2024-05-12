#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        for(int i:nums2) {
            nums1.push_back(i);
        }
        std::sort(nums1.begin(), nums1.end());

        int mid;
        if(nums1.size() % 2 == 0) {
            mid = (nums1.size() / 2) - 1; 
            return (nums1[mid] + nums1[mid+1]) / 2.0;
        } else {
            mid = ceil(nums1.size()/2);
            return nums1[mid];
        }
    }
};

int main () {
    Solution ans;
    std::vector<int> vec1 = {1, 2};
    std::vector<int> vec2 = {3, 4};
    std::cout << ans.findMedianSortedArrays(vec1, vec2);
}