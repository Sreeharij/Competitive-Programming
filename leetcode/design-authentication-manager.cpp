class AuthenticationManager {
private:
    struct ListNode{
        string tokenId;
        int startTime;
        ListNode* next;
        ListNode* prev;
        ListNode(string x,int startingTime){
            tokenId = x;
            startTime = startingTime;
            next = nullptr;
            prev = nullptr;
        }
    };

    int timeToLive;
    ListNode* head;
    ListNode* tail;
public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
        head = nullptr;
        tail = nullptr;
    }
    
    void generate(string tokenId, int currentTime) {
        ListNode* tmp = new ListNode(tokenId,currentTime);
        if(tail){
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        else{
            head = tmp;
            tail = tmp;
        }
    }

    ListNode* deleteNode(ListNode* ptr){
        if(ptr->prev){
            ptr->prev->next = ptr->next;
            if(ptr->next)ptr->next->prev = ptr->prev;
            else tail = ptr->prev;
        }
        else{
            head = ptr->next;
            if(!head)tail = nullptr;
            else head->prev = nullptr;
        }
        ListNode* answer = ptr->next;
        delete ptr;
        return answer;
    }
    
    void renew(string tokenId, int currentTime) {
        ListNode* ptr = head;
        while(ptr){
            if(ptr->tokenId == tokenId){
                if(ptr->startTime + timeToLive <= currentTime){
                    ptr = deleteNode(ptr);
                }
                else{
                    ptr->startTime = currentTime;
                }
                break;
            }
            ptr = ptr->next;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int answer = 0;
        ListNode* ptr = head;
        while(ptr){
            if(ptr->startTime + timeToLive <= currentTime){
                ptr = deleteNode(ptr);
            }
            else{
                answer++;
                ptr = ptr->next;
            }
        }
        return answer;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */