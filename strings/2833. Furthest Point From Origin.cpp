class Solution {
public:
    int furthestDistanceFromOrigin(std::string moves) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);
        char mst_freq = std::count(moves.begin(), moves.end(), 'L') > std::count(moves.begin(), moves.end(), 'R') ? 'L' : 'R';
        
        int dist = 0;
        for (char ch : moves) {
            if (ch == 'L') dist -= 1;
            else if (ch == 'R') dist += 1;
            else {
                mst_freq == 'R' ? dist += 1 : dist -= 1;
            }
        }

        return std::abs(dist);
    }
};

