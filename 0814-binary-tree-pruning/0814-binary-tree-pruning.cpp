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
    bool check(TreeNode* root){
        if(!root){
            return false;
        }
        if(root->val==1){
            return true;
        }
        return check(root->left)||check(root->right);
    }
    void helper(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left){
            if(!check(root->left)){
                root->left=NULL;
            }
        }
        if(root->right){
            if(!check(root->right)){
                root->right=NULL;
            }
        }
        helper(root->left);
        helper(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        helper(root);
        if(root->val==0&&!root->left&&!root->right){
            return NULL;
        }
        return root;
    }
};