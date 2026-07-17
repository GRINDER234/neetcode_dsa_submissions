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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode * curr = head;
        while(curr != nullptr){
            curr = curr->next;
            count = count + 1;
        }

        if(n == count){
            ListNode * curr = head->next;
            delete head;
            return curr;
        }



        // int nodeidx = count - n + 1;
        int prevnodeidx = count - n - 1;

        int x = 0;
        curr = head;
        while(x != prevnodeidx){
            curr = curr->next;
            x = x + 1;
        }

        ListNode * nextnode = curr->next;
        curr->next = nextnode->next;
        delete nextnode;
        return head;
    }
};
