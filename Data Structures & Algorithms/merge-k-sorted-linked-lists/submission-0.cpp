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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        if(n == 1) return lists[0];
        ListNode * head = lists[0];

        for(int i=1; i<n; i++){
            ListNode * dummy = new ListNode(-176036);
            ListNode * curr = dummy;

            ListNode * curr1 = head;
            ListNode * curr2 = lists[i];

            while(curr1 != nullptr && curr2 != nullptr){
                if(curr1->val <= curr2->val){
                    curr->next = curr1;
                    curr1 = curr1->next;
                }else{
                    curr->next = curr2;
                    curr2 = curr2->next;
                }
                curr = curr->next;
            }

            if(curr1 != nullptr){
                curr->next = curr1;
            }else if(curr2 != nullptr){
                curr->next = curr2;
            }

            head = dummy->next;
            delete dummy;
        }

        return head;
    }
};
