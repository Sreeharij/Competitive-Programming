//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/

//CHECK FOR CASE WHEN VALUE OF NODE IS 0 
class Solution{
public:
    Node* make_tree(string str,int idx){
        stack<char> bracket_stack;
        if(str[idx] == ')'){
            return nullptr;
        }
        int number = 0;
        while(str[idx] != '(' && str[idx] != ')' && str[idx] != '\0'){
            number = number*10 + (int)(str[idx] - '0');
            idx++;
        }
        int first,second;
        Node* t = new Node(number);
        if(str[idx] == '('){
            idx++;
            first = idx;
            bracket_stack.push('(');
            while(!bracket_stack.empty()){
                if(str[idx] == '('){
                    bracket_stack.push('(');
                }
                else if(str[idx] == ')'){
                    bracket_stack.pop();
                }
                idx++;
            }
            if(str[idx] == ')' || str[idx] == '\0'){
                t->left = make_tree(str,first);
                return t;
            }
            idx++;
            second = idx;
            t->left = make_tree(str,first);
            t->right = make_tree(str,second);
        }
        
        return t;
        
    }
    
    Node *treeFromString(string str){
        Node* root = make_tree(str,0);
        return root;
    }
};

        


//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
