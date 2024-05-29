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
    TreeNode* make_tree(vector<int>& inorder, vector<int>& postorder,int &post_idx,int in_start,int in_end){
        if(in_start > in_end){
            return nullptr;
        }
        TreeNode* ptr = new TreeNode(postorder[post_idx]);
        int pivot;
        for(int i=in_start;i<=in_end;i++){
            if(inorder[i] == postorder[post_idx]){
                pivot = i;
                break;
            }
        }
        post_idx--;
        ptr->right = make_tree(inorder,postorder,post_idx,pivot+1,in_end);
        ptr->left = make_tree(inorder,postorder,post_idx,in_start,pivot-1);

        return ptr;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int post_idx = postorder.size()- 1;
        return make_tree(inorder,postorder,post_idx,0,postorder.size()- 1);
    }
};
