/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    pair<int,int> answer;
    int pred = -1;
    int succ = -1;
    TreeNode* ptr = root;
    while(ptr){
        if(ptr->data < key){
            pred = ptr->data;
            ptr = ptr->right;
        }
        else{
            ptr = ptr->left;
        }
    }
    ptr = root;
    while(ptr){
        if(ptr->data > key){
            succ = ptr->data;
            ptr = ptr->left;
        }
        else{
            ptr = ptr->right;
        }
    }
    answer.first = pred;
    answer.second = succ;
    return answer;
}
