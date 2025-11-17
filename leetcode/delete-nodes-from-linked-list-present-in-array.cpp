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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(0,head);
        unordered_set<int> setNumbers;
        setNumbers.insert(nums.begin(),nums.end());
        ListNode* trail = dummy;
        ListNode* ptr = head;
        while(ptr){
            if(setNumbers.count(ptr->val)){
                trail->next = ptr->next;

                ptr = trail->next;
            }
            else{
                trail = ptr;
                ptr = ptr->next;
            }
        }
        ListNode* answer = dummy->next;
        delete dummy;
        return answer;
    }
};