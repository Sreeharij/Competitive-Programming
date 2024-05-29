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
    int search(vector<int>&inorder,int start,int end,int key){
        for(int i=start;i<=end;i++){
            if(inorder[i] == key){
                return i;
            }
        }
        return -1;
    }

    TreeNode* make_tree(vector<int>& preorder, vector<int>& inorder,int &pre_idx,int in_start,int in_end){
        if(in_start > in_end){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[pre_idx]); 
        int current_inorder_idx = search(inorder,in_start,in_end,preorder[pre_idx]);
        pre_idx += 1;
        root->left = make_tree(preorder,inorder,pre_idx,in_start,current_inorder_idx-1);
        root->right = make_tree(preorder,inorder,pre_idx,current_inorder_idx+1,in_end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_idx = 0;
        TreeNode* root = make_tree(preorder,inorder,pre_idx,0,inorder.size()-1);
        return root;
    }
};
