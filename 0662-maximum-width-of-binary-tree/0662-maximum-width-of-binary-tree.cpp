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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int currLS = q.size();
            long long minIndex = q.front().second;
            long long stridx = 0, endidx = 0;
            
            for (int i = 0; i < currLS; i++) {
                auto curr = q.front();
                q.pop();
                
                TreeNode* node = curr.first;
                long long idx = curr.second - minIndex;
                
                if (i == 0) stridx = idx;
                if (i == currLS - 1) endidx = idx;
                
                if (node->left) {
                    q.push({node->left, idx * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, idx * 2 + 2});
                }
            }
            maxWidth = max(maxWidth,endidx - stridx + 1);
        }
        return maxWidth;
    }
};