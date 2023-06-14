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
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, -1});
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto p = q.front();
                TreeNode* curr = p.first;
                int grandParent = p.second;
                q.pop();
                if (curr -> left) {
                    if (grandParent % 2 == 0) {
                        ans += curr -> left -> val;
                    }
                    q.push({curr -> left, curr -> val});
                }
                if (curr -> right) {
                    if (grandParent % 2 == 0) {
                        ans += curr -> right -> val;
                    }
                    q.push({curr -> right, curr -> val});
                }
            }
        }
        return ans;
    }
};