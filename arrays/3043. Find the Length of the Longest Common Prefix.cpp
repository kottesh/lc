class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        std::unordered_set<int> store;    


        for (int val : arr1) {
            while (val) {
                if (!store.contains(val))
                    store.insert(val);
                val /= 10;
            }
        }

        int mx_len = 0;
        for (int val : arr2) {
            while (val) {
                if (store.contains(val)) {
                    int len = std::to_string(val).length();
                    mx_len = std::max(mx_len, len);
                }
                val /= 10;
            }
        }

        return mx_len;
    }
    //int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    //    std::ios_base::sync_with_stdio(false);
    //    std::cin.tie(0); std::cout.tie(0);

    //    std::unordered_set<std::string> store;    

    //    for (auto val : arr1) {
    //        std::string str = to_string(val);
    //        for (int i = 1; i <= str.length(); i++) {
    //            if (store.find(str.substr(0, i)) == store.end())
    //                store.insert(str.substr(0, i));
    //        } 
    //    }
    //        
    //    int mx_len = 0;
    //    for (auto val : arr2) {
    //        std::string str = to_string(val);
    //        
    //        int temp_len = 0;
    //        for (int i = 1; i <= str.length(); i++) {
    //            if (store.find(str.substr(0, i)) != store.end())
    //                temp_len = i;
    //        }
    //        mx_len = std::max(mx_len, temp_len);
    //    }

    //    return mx_len;
    //}

    //int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
    //    std::ios_base::sync_with_stdio(false);
    //    std::cin.tie(0); std::cout.tie(0);

    //    std::string s_1, s_2;
    //    
    //    int mx_len = INT_MIN;
    //    for (int val1 : arr1) {
    //        for (int val2 : arr2) {
    //            s_1 = to_string(val1); s_2 = to_string(val2);
    //            
    //            int min_len = std::min(s_1.length(), s_2.length());
    //            int temp_len = 0;
    //            for (int i = 0; i < min_len; i++) {
    //                if (s_1[i] == s_2[i]) {
    //                    temp_len++;
    //                } else {
    //                    break;
    //                }
    //            }

    //            mx_len = std::max(mx_len, temp_len);
    //        }
    //    }

    //    return mx_len == INT_MIN ? 0 : mx_len;
    //}
};

