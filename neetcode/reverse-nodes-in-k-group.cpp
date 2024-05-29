class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ptr = head;
        int length =0;
        while(ptr){
            length++;
            ptr = ptr->next;
        }
        int possible_multiple = length - (length%k);
        int temp_k;
        ListNode *p=head,*q=nullptr,*r=nullptr,*last = head,*temp_last;

        bool first_time_flag = true;
        
        while(p && possible_multiple){
            temp_k = k;
            temp_last = p;
            while(p && temp_k--){
                r = q;
                q = p;
                p = p->next;
                q->next = r;
                possible_multiple--;
            }
            if(first_time_flag){
                first_time_flag = false;
                head = q;
            }
            else{
                last->next = q;
            }
            last = temp_last;
            q=r=nullptr;    
        }
        last->next = p;
                
        return head;
    }
};