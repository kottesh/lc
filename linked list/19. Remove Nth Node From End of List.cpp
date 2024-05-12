#include  <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;

        int count = 0;
        ListNode *tmp1 = head, *tmp2  = head;
        while(tmp1 != nullptr) {
            count++;
            tmp1 = tmp1->next; 
        }

        int x = count - n, step=1;

        if(x==0)
            return tmp2->next;

        while(step != x) {
            tmp2 = tmp2->next;
            step++;
        }

        tmp2->next = (tmp2->next->next != nullptr) ? tmp2->next->next : nullptr;

        return head;
    }
};

int  main() {
    ListNode *list = nullptr;
    ListNode *walk;

    for(int i=1; i<=2; i++) {
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
    ListNode *res = sol.removeNthFromEnd(list, 1);

    while(res!=nullptr) {
        std::cout<<res->val<<", ";
        res = res->next;
    }
}