#include <bits/stdc++.h>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());

        int count = 0;

        int l = 0, r = people.size() - 1;

        while (l <= r) {
            count++;
            if (people[l] + people[r] <= limit) {
                l++;
            }
            r--;
        }
        return count;
    }
};

int main() {
    std::vector<int> peps {2, 4};
    std::cout << (new Solution()) -> numRescueBoats(peps, 5);
    return 0;
}