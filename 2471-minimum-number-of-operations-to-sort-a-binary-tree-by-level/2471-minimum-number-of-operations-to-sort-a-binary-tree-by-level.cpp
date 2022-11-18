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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int> v;
            while(sz--){
                TreeNode* curr=q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            if(v.size()>0){
                ans.push_back(v);
            }
        }
        int res=0;
        for(int i=0;i<ans.size();i++){
            int n=ans[i].size();
            vector<bool> vis(n,false);
            vector<pair<int,int>> pos(n);
            for(int j=0;j<n;j++){
                pos[j].first=ans[i][j];
                pos[j].second=j;
            }
            sort(pos.begin(),pos.end());
            for(int j=0;j<n;j++){
                if(vis[j]||pos[j].second==j){
                    continue;
                }
                int cycle_size=0;
                int k=j;
                while(!vis[k]){
                    vis[k]=true;
                    k=pos[k].second;
                    cycle_size++;
                }
                if(cycle_size>0){
                    res+=cycle_size-1;
                }
            }
        }
        return res;
    }
};