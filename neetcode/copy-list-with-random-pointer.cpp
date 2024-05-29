/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }

        Node *answer = new Node(head->val);
        Node *ptr1 = head->next;
        Node *ptr2 = answer;

        unordered_map <Node*,Node*> hash_map;
        hash_map[nullptr] = nullptr;
        hash_map[head] = answer;
        
        while(ptr1){
            Node *t = new Node(ptr1->val);
            ptr2->next = t;
            ptr2 = t;
            hash_map[ptr1] = ptr2;
            ptr1 = ptr1->next;
        }

        ptr1 = head;
        ptr2 = answer;

        while(ptr1){
            hash_map[ptr1]->random = hash_map[ptr1->random];
            ptr1 = ptr1->next;
        }
        return answer;
    }
};