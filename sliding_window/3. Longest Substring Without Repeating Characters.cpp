#include <bits/stc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       std::unordered_map<char, int> seen;
       
       int l = 0, r = 0;
       int longest = 0;
       //for (int i = 0; i < s.length(); i++) {
       //    if (seen.find(s[i]) != seen.end()) {
       //        r++;
       //        seen[s[i]] = i;
       //    } else {
       //        l = seen[s[i]] + 1;
       //        r++;
       //    }
       //    longest = std::max(longest, (r - l + 1));
       //}

       while (r < s.length()) {
           if (seen.find(s[r]) == seen.end()) {
               seen[s[r]] = r;
           } else {
               l = seen[s[r]] + 1;
               seen[s[r]] = r;
           }
           longest = std::max(longest, (r - l + 1));
           r++;
       }
       
       return longest;
    }
};
