#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> answer;
    TreeNode *ptr = root;
    TreeNode *predecessor;

    while(ptr){
        if(ptr->left == NULL){
            answer.push_back(ptr->data);
            ptr = ptr->right;
        }
        else{
            predecessor = ptr->left;
            while(predecessor->right && predecessor->right != ptr){
                predecessor = predecessor->right;
            }
            if(predecessor->right == NULL){
                predecessor->right = ptr;
                answer.push_back(ptr->data);
                ptr = ptr->left;
            }
            else{
                predecessor->right = NULL;
                ptr = ptr->right;
            }
        }
    }
    return answer;

}
