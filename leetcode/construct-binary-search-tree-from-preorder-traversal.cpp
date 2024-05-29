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
    TreeNode* build_tree(vector<int>& preorder,int &idx,int upper_bound){
        if(idx == preorder.size() || preorder[idx] > upper_bound){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = build_tree(preorder,idx,root->val);
        root->right = build_tree(preorder,idx,upper_bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return build_tree(preorder,idx,INT_MAX);
    }
};
