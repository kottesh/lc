#include <bits/stdc++.h>


class MyCalendar {
private:
    std::vector<std::vector<int>> events;
public:
    bool book(int start, int end) {
        for (auto event : events) {
            if (start < event[1] && end > event[0])
                return false;
        }

        events.push_back({start, end});
        return true;
    }
};

int main() {
    return 0;
}
