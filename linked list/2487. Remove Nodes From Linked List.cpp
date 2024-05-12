#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef ListNode Node;

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // if there is either one or no nodes then the condition is met.
        // return head.  _(empty) or (8)->nullptr
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* next = removeNodes(head->next);

        if (head->val < next->val) {
            return next;
        }

        head->next = next;
        return head;
    }
};

int main() {
    return 0;
}