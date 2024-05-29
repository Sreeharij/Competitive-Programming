#include <bits/stdc++.h> 
struct Node{
    Node* children[26] = {nullptr};
    bool is_word = false;
};

void insert(string& word,Node* root){
    Node* ptr = root;
    int length = 0;
    for(char letter: word){
        int idx = letter - 'a';
        if(!ptr->children[idx]){
            ptr->children[idx] = new Node;
        }
        ptr = ptr->children[idx];
    }
    ptr->is_word = true;
}

void check(Node* ptr,string& word,string& longest){
    for(char letter: word){
        int idx = letter - 'a';
        if(!ptr->children[idx]){
            return;
        }
        ptr = ptr->children[idx];
        if(ptr->is_word == false){
            return;
        }
    }
    if((word.size() > longest.size()) || (word.size() == longest.size() && word < longest)){
        longest = word;
    }
    return;
}

string completeString(int n, vector<string> &a){
    Node* root = new Node();
    string longest = "";
    for(string& word: a){
        insert(word,root);
    }
    for(string& word: a){
        check(root,word,longest);
    }
    return longest.size() == 0 ? "None" : longest;
}