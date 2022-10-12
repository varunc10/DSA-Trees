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
    vector<int> v;
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        return root->val+helper(root->left)+helper(root->right);
    }
    void helper1(TreeNode* root){
        if(!root){
            return;
        }
        v.push_back(helper(root));
        helper1(root->left);
        helper1(root->right);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper1(root);
        unordered_map<int,int> m;
        for(auto i:v){
            m[i]++;
        }
        int mx_freq=INT_MIN,mx_val=INT_MIN;
        for(auto i:m){
            if(i.second>mx_freq){
                mx_freq=i.second;
                mx_val=i.first;
            }
        }
        vector<int> ans;
        for(auto i:m){
            if(i.second==mx_freq){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};