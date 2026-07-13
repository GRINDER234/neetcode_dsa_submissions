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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * l1 = list1;
        ListNode * l2 = list2;

        if(!l1) return l2;
        if(!l2) return l1;
        ListNode * dummyNode = new ListNode(-8999);
        ListNode * curr = dummyNode;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if(l1 != nullptr){
            curr->next = l1;
        }else if(l2 != nullptr){
            curr->next = l2;
        }
        
        return dummyNode->next;
    }
};
