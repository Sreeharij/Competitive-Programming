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
    void get_inorder(TreeNode* ptr,vector<int> &arr){
        if(ptr == nullptr){
            arr.push_back(100000);
            return;
        };

        get_inorder(ptr->left,arr);
        arr.push_back(ptr->val);
        get_inorder(ptr->right,arr);
    }

    void get_preorder(TreeNode* ptr,vector<int> &arr){
        if(ptr == nullptr){
            arr.push_back(100000);
            return;
        };


        arr.push_back(ptr->val);
        get_preorder(ptr->left,arr);
        get_preorder(ptr->right,arr);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> inorder_p,inorder_q,preorder_p,preorder_q;
        get_inorder(p,inorder_p);
        get_inorder(q,inorder_q);
        get_preorder(p,preorder_p);
        get_preorder(q,preorder_q);
        if(!(inorder_p.size() == inorder_q.size() && preorder_p.size() == preorder_q.size())){
            return false;
        }
        for(int i=0;i<inorder_p.size();i++){
            if(inorder_p[i] != inorder_q[i]){
                return false;
            }
        }
        for(int i=0;i<preorder_p.size();i++){
            if(preorder_p[i] != preorder_q[i]){
                return false;
            }
        }
        return true;
    }
};
