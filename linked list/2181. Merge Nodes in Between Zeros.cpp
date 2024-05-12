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
    ListNode* mergeNodes(ListNode* head) {
        if (!head) return head;

        Node* newHead = nullptr;
        Node* mover = newHead;

        int count = 0;
        while (head != nullptr) {
            if (head->val != 0) {
                count += head->val;
            } else {
                if (count != 0) {
                    if (!newHead) {
                        newHead = new Node(count);
                        mover = newHead; 
                    } else {
                        mover->next = new Node(count);
                        mover = mover->next;
                    }
                    count = 0;
                }
            }
            head = head->next;
        }
        return newHead;
    }
};

int main() {
    return 0;
}