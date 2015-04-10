/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumHelper(TreeNode* croot, int sum){
        if(croot == NULL){
            return 0;
        }
        if(croot->left == NULL && croot->right == NULL){
            return sum * 10 + croot->val;
        }

        return sumHelper(croot->left, ((sum*10) + croot->val) ) + sumHelper(croot->right, ((sum*10) + croot->val));
    }
    
    int sumNumbers(TreeNode *root) {
        return sumHelper(root, 0);
    }
};