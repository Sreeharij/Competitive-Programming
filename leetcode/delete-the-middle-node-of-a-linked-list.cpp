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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* trail = nullptr;
        if(!fast){
            return nullptr;
        }

        while(fast){
            trail = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
        }
        trail->next = trail->next->next;
        return head;

    }
};