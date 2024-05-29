#include <bits/stdc++.h> 
/*************************************************************
    Following is the Binary Search Tree node structure

    class BinaryTreeNode {

      public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/

struct return_data{
    bool is_bst;
    int max_val;
    int min_val;
    int bst_sum;
};

struct return_data get_bst(BinaryTreeNode<int>* root,int &max_sum){
    if(!root){
        return {true,INT_MIN,INT_MAX,0};
    }
    struct return_data left_data = get_bst(root->left,max_sum);
    struct return_data right_data = get_bst(root->right,max_sum);
    bool flag = false;
    if(left_data.is_bst && right_data.is_bst){
        if((root->data > left_data.max_val) && (root->data < right_data.min_val)){
            flag = true;
        }
    }
    int bst_sum = left_data.bst_sum + right_data.bst_sum;
    bst_sum = flag ? bst_sum + root->data : 0;
    max_sum = max_sum > bst_sum ? max_sum : bst_sum;
    return {flag,max(root->data,right_data.max_val),min(root->data,left_data.min_val),bst_sum};
}

int maximumSumBST(BinaryTreeNode<int>* root){
    int max_sum = 0;
    get_bst(root,max_sum);
    return max_sum;

}
