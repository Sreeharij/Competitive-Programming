//SOLUTION USING DEPTH FIRST SEARCH APPROACH GIVEN BELOW

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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        int max_height  = x > y ? x : y;
        return max_height+1;
    }
};





//SOLUTION USING BREAD FIRST SEARCH GIVEN APPROACH BELOW
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode* > q;
        TreeNode* ptr;
        int level = 0;
        if(root){
            q.push(root);
        }
        int current_queue_size;
        while(!q.empty()){
            current_queue_size = q.size();
            for(int i=0;i<current_queue_size;i++){
                ptr = q.front();
                q.pop();
                if(ptr->left){
                    q.push(ptr->left);
                }
                if(ptr->right){
                    q.push(ptr->right);
                }
            }
            level += 1;
        }
        return level;
    }
};