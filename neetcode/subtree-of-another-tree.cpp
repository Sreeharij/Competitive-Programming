/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check_equality(TreeNode* A,TreeNode* B){
        if((A == nullptr && B!= nullptr) || (A != nullptr && B == nullptr)){
            return false;
        }
        if(!A && !B){
            return true;
        }
        else{
            if(A->val != B->val){
                return false;
            }
            else{ 
                return check_equality(A->left,B->left) && check_equality(A->right,B->right);
            }
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){
            return false;
        }
        return check_equality(root,subRoot) || isSubtree(root->left,subRoot) ||  isSubtree(root->right,subRoot);
    }
};
