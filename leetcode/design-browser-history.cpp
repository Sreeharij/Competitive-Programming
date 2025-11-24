class BrowserHistory {
    struct ListNode{
        string val;
        struct ListNode* next;
        struct ListNode* prev;
        ListNode(string x){
            val = x;
            next = nullptr;
            prev = nullptr;
        }
        ListNode(string x, ListNode* forward,ListNode* backward){
            val = x;
            next = forward;
            prev = backward;
        }
    };
    ListNode* ptr;

public:
    BrowserHistory(string homepage){
        ptr = new ListNode(homepage);
    }
    
    void deleteRemaining(ListNode* ptr){
        ListNode* temp = ptr;
        while(ptr){
            ptr = ptr->next;
            delete temp;
            temp = ptr;
        }
    }

    void visit(string url) {
        ListNode* newNode = new ListNode(url);
        newNode->prev = ptr;
        deleteRemaining(ptr->next);
        ptr->next = newNode;
        ptr = newNode;
    }
    
    string back(int steps) {    
        while(ptr->prev && steps > 0){
            ptr = ptr->prev;
            steps--;
        }
        return ptr->val;
    }
    
    string forward(int steps) {
        while(ptr->next && steps > 0){
            ptr = ptr->next;
            steps--;
        }
        return ptr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */