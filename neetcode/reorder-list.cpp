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
    void reorderList(ListNode* head) {
        ListNode *ptr = head;
        ListNode *end_of_list = nullptr;
        int length = 0;
        while(ptr){
            end_of_list = ptr;
            length++;
            ptr = ptr->next;
        }
        int l1_length,l2_length;
        if(length%2==0){
            l2_length = length/2;
        }
        else{
            l2_length = (length-1)/2;
        }
        l1_length = length - l2_length;

        ptr = head;
        ListNode *trail = nullptr;
        for(int i=0;i<l1_length;i++){
            trail = ptr;
            ptr = ptr->next;
        } 
        trail->next = nullptr;
        trail = nullptr;
        ListNode *trail2 = nullptr;

        while(ptr){
            trail2 = trail;
            trail = ptr;
            ptr = ptr->next;
            trail->next = trail2;
        }
        trail = trail2 = nullptr;
        ptr = head;
        
        ListNode *ptr1 = head;
        ListNode *ptr2 = end_of_list;

        while(ptr1){
            ptr1 = ptr1->next;
            ptr->next = ptr2;
            if(ptr->next){
                ptr2 = ptr2->next;
                ptr->next->next = ptr1;
            }
            ptr = ptr1;
        }
    }
};