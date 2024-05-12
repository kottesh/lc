#include <iostream>
#include <cmath>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    float listLen(ListNode *head) {
        float len = 0;
        while(head != nullptr) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return head;
        
        float len = listLen(head);
        len = ((int)len % 2 == 0) ? len + 1 : len;
        float mid = ceil(len / 2);

        int step = 1;
        while(step != mid) {
            head = head->next;
            step++;
        }
        return head;
    }
};

int  main() {
    ListNode *list = nullptr;
    ListNode *walk;

    for(int i=1; i<=6; i++) {
        if(list == nullptr) {
            list = new ListNode(i);
            walk = list;
        }
        else {
            walk->next = new ListNode(i);
            walk = walk->next; 
        }
    }

    Solution sol;
    ListNode *res = sol.middleNode(list);

    while(res!=nullptr) {
        std::cout<<res->val<<", ";
        res = res->next;
    }
}