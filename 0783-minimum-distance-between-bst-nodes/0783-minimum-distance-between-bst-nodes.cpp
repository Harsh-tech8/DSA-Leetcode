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
     
    TreeNode* pve = NULL;
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        if (root == NULL){
            return INT_MAX;
        }

        if (root->left){
            int  leftmin = minDiffInBST(root->left);
            ans = min (ans,leftmin);
        }
        if (pve != NULL){
            ans = min(ans , root->val - pve->val);
        }
        pve = root;
        if (root->right){
            int rightmin = minDiffInBST(root->right);
            ans = min (ans,rightmin);
        }
         return ans;
       
    }
    
};