/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* ptr,TreeNode* p,TreeNode* q,TreeNode* &answer){
        if(!ptr)return false;
        bool left = solve(ptr->left,p,q,answer);
        bool right = solve(ptr->right,p,q,answer);

        if(left || right){
            if(left == right || ptr == p || ptr == q)answer = ptr;
            return true;
        }

        if(ptr == p || ptr == q){
            return true;
        }
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* answer = nullptr;
        solve(root,p,q,answer);
        return answer;   
    }
};