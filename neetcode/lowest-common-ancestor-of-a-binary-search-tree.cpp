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
    int find_father(TreeNode* root,TreeNode* p,TreeNode* q,int flag_count,TreeNode* &answer){
        if(root == nullptr){
            return 0;
        }
        int left_flag_count = find_father(root->left,p,q,flag_count,answer);
        int right_flag_count = find_father(root->right,p,q,flag_count,answer);
        flag_count = left_flag_count + right_flag_count;

        if(root->val == p->val || root->val == q->val){
            flag_count += 1;
        }

        if(flag_count == 2 && answer == nullptr){
            answer = root;
        }
        return flag_count;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* answer = nullptr;
        find_father(root,p,q,0,answer);
        return answer;
    }
};


//MOST EFFICIENT OPTIMAL ANSWER GIVEN BELOW
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
//         TreeNode* ptr = root;
//         while(ptr){
//             if(p->val < ptr->val && q->val < ptr->val){
//                 ptr = ptr->left;
//             }
//             else if(p->val > ptr->val && q->val > ptr->val){
//                 ptr = ptr->right;
//             }
//             else{
//                 return ptr;
//             }
//         }
//         return nullptr;
//     }
// };
