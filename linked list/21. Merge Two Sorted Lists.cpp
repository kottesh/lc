#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *res = nullptr, *dummy;
        
        if(list1 == nullptr) {
            return list2;
        } else if(list2 == nullptr) {
            return list1;
        }

        while (list2 != nullptr) {
            if(res == nullptr) {
                res = list2;
                dummy = res;
            } else {
                dummy->next = list2;
            }
            list2 = list2->next;

            if(list1->next == nullptr) {
                dummy->next = list1;
                break;
            }

            while((list1->next)->val <= list2->val) {
                dummy->next = list1;
                list1 = list1->next;
                dummy = dummy->next;
            }
        }
        return res;
    }
};

int main() {
    ListNode *l1 = nullptr, *l2 = nullptr, *tmp1, *tmp2;
    
    for(int i=1; i<=3; i++) {
        if(l1 == nullptr) {
            l1 = new ListNode(i); 
            l2= new ListNode(i+1); 
            tmp1 = l1;
            tmp2 = l2;
        }
        else {
            tmp1->next = new ListNode(i); 
            tmp2->next = new ListNode(i+1); 
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }

    Solution sol;
    ListNode *l3 = sol.mergeTwoLists(l1, l2);

    while(l3 !=nullptr) {
        std::cout<<l3->val<<", ";
        l3 = l3->next;
    }

    return 0;
}