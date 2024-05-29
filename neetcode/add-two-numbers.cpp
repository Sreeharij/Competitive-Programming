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


//METHOD 1 
//RECURSIVE APPROACH
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *answer = recursive_addition(l1,l2,0);
        return answer;
    }

    ListNode *recursive_addition(ListNode* l1, ListNode* l2,int carry_over){
        int x=0,y=0;
        ListNode *next_l1=nullptr, *next_l2 = nullptr;
        if(l1){
            x = l1->val;
            next_l1 = l1->next;
        }
        if(l2){
            y = l2->val;
            next_l2 = l2->next;
        }

        if(l1==nullptr && l2==nullptr){
            if(carry_over){
                ListNode *t = new ListNode;
                t->val = carry_over;
                return t;
            }
            return nullptr;
        }

        int sum = x + y + carry_over;
        carry_over = sum/10;
        sum = sum%10;

        ListNode *t = new ListNode;
        t->val = sum;
        t->next = recursive_addition(next_l1,next_l2,carry_over);

        return t;
    }
};


//METHOD 2
//ITERATIVE APPROACH
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry_over = 0;
        ListNode *answer = nullptr;
        ListNode *ptr = answer;
        int x,y;

        while(l1 || l2 || carry_over){
            x=y=0;            
            if(l1){
                x = l1->val;
                l1 = l1->next;
            }
            if(l2){
                y = l2->val;
                l2 = l2->next;
            }
            if(!answer){
                answer = new ListNode;
                ptr = answer;
            }
            else{
                ptr->next = new ListNode;
                ptr = ptr->next;
            }
            ptr->val = x + y + carry_over;
            carry_over = (ptr->val)/10;
            ptr->val %= 10;
        }

        return answer;
    }

};