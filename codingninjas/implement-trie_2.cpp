#include <bits/stdc++.h> 
class Trie{
    private:
        struct Node{
          Node *children[26] = {nullptr};
          int word_count = 0;
          int child_count = 0;
        };

        Node* root;
    public:

    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node* ptr = root;
        for(char letter: word){
            int idx = letter - 'a';
            if(!ptr->children[idx]){
                ptr->children[idx] = new Node();
            }
            ptr = ptr->children[idx];
            ptr->child_count++;
        }
        ptr->word_count++;
    }

    int countWordsEqualTo(string &word){
        Node* ptr = root;
        for(char letter: word){
            int idx = letter-'a';
            if(!ptr->children[idx]){
                return 0;
            }
            ptr = ptr->children[idx];
        }
        return ptr->word_count;
    }

    int countWordsStartingWith(string &word){
        Node* ptr = root;
        for(char letter: word){
            int idx = letter - 'a';
            if(!ptr->children[idx]){
                return 0;
            }
            ptr = ptr->children[idx];
        }
        return ptr->child_count;
    }

    void erase(string &word){
        Node* ptr = root;
        Node* parent = nullptr;
        int idx;
        for(char letter: word){
            parent = ptr;
            idx = letter - 'a';
            ptr = ptr->children[idx];
            ptr->child_count--;
        }
        ptr->word_count--;
        if(ptr->word_count == 0 && ptr->child_count == 0){
            parent->children[idx] = nullptr;
            free(ptr);
        }
    }
};
