class Trie {
private:
    struct Node{
        Node* children[26];
        bool is_word;
        Node(){
            is_word = false;
            fill(begin(children),end(children),nullptr);
        }
    };
    Node* head;
public:
    Trie(){
        head = new Node();
    }
    
    void insert(string word){
        Node* ptr = head;
        for(char letter: word){
            int idx = letter-'a';
            if(!ptr->children[idx]){
                ptr->children[idx] = new Node();
            }
            ptr = ptr->children[idx];
        }
        ptr->is_word = true;
    }
    
    bool search(string word) {
        Node* ptr = head;
        for(char letter: word){
            int idx = letter-'a';
            if(!ptr->children[idx]){
                return false;
            }
            ptr = ptr->children[idx];
        }
        return ptr->is_word;
    }
    
    bool startsWith(string prefix) {
        Node* ptr = head;
        for(char letter: prefix){
            int idx = letter-'a';
            if(!ptr->children[idx]){
                return false;
            }
            ptr = ptr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */