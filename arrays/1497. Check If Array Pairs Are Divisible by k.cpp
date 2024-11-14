class Solution {
public:
    bool canArrange(std::vector<int>& arr, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        std::vector<int> freq(k, 0);

        for (int num : arr) {
            int rem = num % k;
            rem = (rem < 0) ? rem + k : rem;
            freq[rem]++;
        }

        if (freq[0] % 2 != 0) return false;
        
        for (int i = 1; i <= k/2; i++) {
            if (freq[i] != freq[k - i])
                return false;
        }

        return true;
    }
};
