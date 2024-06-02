//Below approach uses ordered multiset which takes O(nlogn) where n is the total number of nodes and k is the number of lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* head;
        multiset<int> st;
        for(auto list: lists){
            ListNode* ptr = list;
            if(ptr == nullptr) continue;
            while(ptr){
                st.insert(ptr->val);
                ptr = ptr->next;
            }
        }
        if(st.begin() == st.end()) return nullptr;
        ListNode* ptr = head;
        head = new ListNode(*st.begin());
        st.erase(st.begin());
        for(int val: st){
            ptr->next = new ListNode(val);
            ptr = ptr->next;
        }
        return head;
    }
};

//Below approach uses O(nlogk) where n is the total number of nodes and k is the number of lists
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
    ListNode* merge_list(ListNode* l1,ListNode* l2){
        ListNode* head;
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        if(l1->val <= l2->val){
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;
        }
        ListNode* ptr = head;
        while(l1 && l2){
            if(l1->val <= l2->val){
                ptr->next = l1;
                ptr = ptr->next;
                l1 = l1->next;
            }
            else{
                ptr->next = l2;
                ptr = ptr->next;
                l2 = l2->next;
            }
        }
        if(l1){
            ptr->next = l1;
        }
        if(l2){
            ptr->next = l2;
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* head;
        int length = lists.size();
        while(length > 1){
            for(int i=0;i<length/2;i++){
                if(i == length-i-1) continue;
                lists[i] = merge_list(lists[i],lists[length-i-1]);
            }
            length = (length+1)/2;
        }
        head = lists[0];
        return head;
    }
};