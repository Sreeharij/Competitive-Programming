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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return head;
        }
        ListNode *ptr = head;
        ListNode *end_of_list = nullptr;
        int length = 0;
        while(ptr){
            length++;
            end_of_list = ptr;
            ptr = ptr->next;
        }
        k = k%length;
        ptr = head;
        for(int i=0;i<length-k-1;i++){
            ptr = ptr->next;
        }
        end_of_list->next = head;
        head = ptr->next;
        ptr->next = nullptr;
        return head;
    }
};