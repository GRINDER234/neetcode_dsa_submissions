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
private:
    ListNode * reverse(ListNode * head){
        ListNode * curr = head;
        ListNode * nextptr = nullptr;
        ListNode * prev = nullptr;

        while(curr != nullptr){
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }

        return prev;
    }

public:
    void reorderList(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode * nextptr = slow->next;
        slow->next = nullptr;
        ListNode * head1 = head;
        ListNode * head2 = reverse(nextptr);

        ListNode * dummyNode = new ListNode(-8999);
        ListNode * curr = dummyNode;
        int flag = 0;
        while(head1 != nullptr && head2 != nullptr){
            if(flag == 0){
                curr->next = head1;
                head1 = head1->next;
                flag = 1;
            }else{
                curr->next = head2;
                head2 = head2->next;
                flag = 0;
            }

            curr = curr->next;
        }

        if(head1 != nullptr) curr->next = head1;
        if(head2 != nullptr) curr->next = head2;

        head = dummyNode->next;
        delete dummyNode;
    }
};
