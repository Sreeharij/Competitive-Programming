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
    ListNode* doubleIt(ListNode* head) {
        ListNode* answer = new ListNode(0,head);
        ListNode* ptr = head;
        ListNode* trail = answer;
        while(ptr){
            int current_digit = (2*trail->val)%10;
            trail->val = (ptr->val >= 5) ? current_digit + 1 : current_digit;
            trail = ptr;
            ptr = ptr->next;
        }
        trail->val = (2*trail->val)%10;
        if(answer->val == 0){
            delete answer;
            return head;
        }
        return answer;
    }
};