#include <bits/stdc++.h>

class MedianFinder {
    //e.g: {1, 2, 3, 4};
    std::priority_queue<int, std::vector<int>> lower; // stores 1, 2
    std::priority_queue<int, std::vector<int>, std::greater<int>> upper; // stores 3, 4
public:
    void addNum(int num) {
        // In this am directly pushing the num into the lower heap. So it takes O(log n)
        // in the worst case. In the next check if the top val in lower heap is greater
        // than top val of upper heap. Then I need to remove the top val from the lower heap
        // and again push it into the upper heap. So for removing O(log n) and for inserting again
        // O(log n). I think there is too much removal and insertion. 

        // lower.push(num);

        // if (!upper.empty() && (lower.top() > upper.top())) {
        //         upper.push(lower.top());
        //         lower.pop();
        // }


        // In this approach I will push the value only in the init stage of lower heap and 
        // if the num is less than the top val in the heap. Otherwise I will push into the 
        // upper heap. 

        // In the after stage I will try to balance both the heaps. Means the diff between
        // the heaps should be either 0 or 1 (- and +)[not other than this].
        if (lower.empty() || num <= lower.top()) {
            lower.push(num);
        } else {
            upper.push(num);
        }

        if (lower.size() - upper.size() == 2) {
            upper.push(lower.top());
            lower.pop();
        } else if (lower.size() - upper.size() == -2) {
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if (lower.size() == upper.size())
            return (double)(lower.top() + upper.top()) / 2;

        if (lower.size() > upper.size()) 
            return lower.top();

        return upper.top();
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */