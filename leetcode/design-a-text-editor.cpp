class TextEditor {
private:
    struct ListNode{
        char val;
        ListNode* next;
        ListNode* prev;
        ListNode(char x){
            val = x;
            next = nullptr;
            prev = nullptr;
        }
    };
    ListNode* cursor_position;
    ListNode* head;
public:
    TextEditor() {
        cursor_position = nullptr;
        head = nullptr;
    }
    
    void addText(string text) {
        ListNode* ptr;
        for(auto x: text){
            ptr = new ListNode(x);
            if(cursor_position){
                ptr->next = cursor_position->next;
                ptr->prev = cursor_position;
                if(cursor_position->next)cursor_position->next->prev = ptr;
                cursor_position->next = ptr;
            }
            else{
                ptr->next = head;
                if(head){
                    head->prev = ptr;
                    head = ptr;
                }
                else{
                    head = ptr;
                }
            }
            cursor_position = ptr;
        }
    }
    
    int deleteText(int k) {
        int count = 0;
        ListNode* ptr;
        while(k--){
            if(!cursor_position) return count;
            if(cursor_position->next)cursor_position->next->prev = cursor_position->prev;
            if(cursor_position->prev){
                cursor_position->prev->next = cursor_position->next;
                ptr = cursor_position->prev;
            }
            else{
                head = cursor_position->next;
                ptr = nullptr;
            }
            delete cursor_position;
            cursor_position = ptr;
            count++;
        }
        return count;
    }
    
    string cursorLeft(int k) {
        string answer = "";
        while(k--){
            if(!cursor_position){
                break;
            }
            cursor_position = cursor_position->prev;
        }
        if(!cursor_position)return answer;
        ListNode* ptr = cursor_position;
        for(int i=0;i<10;i++){
            if(!ptr) break;
            ptr = ptr->prev;
        }
        if(!ptr){
            ptr = head;
            answer += ptr->val;
        }
        for(int i=0;i<10;i++){
            if(ptr == cursor_position)break;
            ptr = ptr->next;
            answer += ptr->val;
        }
        return answer;

    }
    
    string cursorRight(int k) {
        string answer = "";
        while(k--){
            if(!cursor_position){
                cursor_position = head;
                continue;
            }
            if(!cursor_position->next) break;
            cursor_position = cursor_position->next;
        }
        if(!cursor_position)return answer;
        ListNode* ptr = cursor_position;
        for(int i=0;i<10;i++){
            if(!ptr) break;
            ptr = ptr->prev;
        }
        if(!ptr){
            ptr = head;
            answer += ptr->val;
        }
        for(int i=0;i<10;i++){
            if(ptr == cursor_position)break;
            ptr = ptr->next;
            answer += ptr->val;
        }
        return answer;

    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */