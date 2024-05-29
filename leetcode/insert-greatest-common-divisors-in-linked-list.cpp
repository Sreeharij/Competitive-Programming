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
    int gcd(int a,int b){
        while(b){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr = head;
        ListNode* trail = nullptr;
        int gcd_val;
        ListNode* x;
        while(ptr->next){
            trail = ptr;
            ptr = ptr->next;
            gcd_val = gcd(ptr->val,trail->val);
            x = new ListNode(gcd_val);
            x->next = ptr;
            trail->next = x;
        }


        return head;
    }
};