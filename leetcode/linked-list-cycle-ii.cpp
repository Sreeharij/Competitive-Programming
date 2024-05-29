/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        if(head == nullptr){
            return head;
        }
        do{
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
        }while(fast && slow!= fast);
        if(fast==nullptr){
            return nullptr;
        }

        ListNode *second = head;
        while(second!=slow){
            slow = slow->next;
            second = second->next;
        }

        return second;
    }
};