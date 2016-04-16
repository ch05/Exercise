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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL){
            return vector<string>();
        }
        vector<string> result;
        if(root->left==NULL && root->right==NULL){  //leaf, base case
            char buffer[32];
            sprintf(buffer,"%d",root->val);
            string value(buffer);
            result.push_back(value);
            return result;
        }
        if(root->left != NULL){
            vector<string> leftVal = binaryTreePaths(root->left);
            result.insert(result.end(), leftVal.begin(), leftVal.end());
        }
        if(root->right != NULL){
            vector<string> rightVal = binaryTreePaths(root->right);
            result.insert(result.end(),rightVal.begin(), rightVal.end());
        }
        char buffer[32];
        sprintf(buffer, "%d", root->val);
        string value(buffer);
        value = value + "->";
        for(int i = 0; i < result.size(); i++){
            result[i] = value + result[i];
        }
        return result;
    }
};