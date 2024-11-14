class Solution {
private:
    //std::vector<std::string> str_pmut; 

    //void generate_permutations(const auto &str, auto &_str, auto &taken) { // _str -> intermediate_string
    //    if (_str.length() == str.length()) {
    //            str_pmut.push_back(_str);
    //            return;
    //    }

    //    for (int i = 0; i < str.length(); i++) {
    //        if (!taken[i]) {
    //            _str += str[i];
    //            taken[i] = !taken[i];
    //            generate_permutations(str, _str, taken);
    //            taken[i] = !taken[i];
    //            _str.pop_back();
    //        }
    //    }
    //}
public:
    bool checkInclusion(string s1, string s2) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        if (s1.length() > s2.length()) return false;

        std::unordered_map<char, int> map_1;
        std::unordered_map<char, int> map_2;

        for (auto ch : s1)
            map_1[ch]++;

        for (int i = 0; i < s1.length(); i++)
            map_2[s2[i]]++;

        if (map_1 == map_2) return true;

        for (int i = s1.length(); i < s2.length(); i++) {
            map_2[s2[i - s1.length()]]--;
            map_2[s2[i]]++;

            if (map_2[s2[i - s1.length()]] == 0) {
                map_2.erase(s2[i - s1.length()]);
            }

            if (map_1 == map_2) return true;
        }

        return false;
    }
    //bool checkInclusion(string s1, string s2) {
    //    std::ios_base::sync_with_stdio(false);
    //    std::cin.tie(0); std::cout.tie(0);

    //    if (s1.length() > s2.length()) return false;

    //    std::vector<bool> taken(s1.size(), false); 
    //    std::string _str;
    //    generate_permutations(s1, _str, taken);

    //    for (auto str : str_pmut) {
    //        if (s2.find(str) != string::npos)
    //            return true;
    //    }

    //    return false;
    //}
};


