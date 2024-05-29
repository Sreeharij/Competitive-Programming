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
    bool compare_nodes(TreeNode* left_branch, TreeNode* right_branch){
        if(( !left_branch && right_branch) || (left_branch && !right_branch)){
            return false;
        }
        if(!left_branch && !right_branch) return true;
        return (left_branch->val == right_branch->val) && compare_nodes(left_branch->left,right_branch->right) && compare_nodes(left_branch->right,right_branch->left);
    }

    bool isSymmetric(TreeNode* root) {
        return compare_nodes(root->left,root->right);
    }
};
