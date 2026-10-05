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
    int ans = 0 ;
    int hight(TreeNode* root){
        if(root == NULL ){
            return 0;

        }
        int lefthig = hight(root->left);
        int righthig = hight(root->right);
        ans = max(ans,lefthig + righthig);

        return max(lefthig,righthig) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        hight (root);
        return ans;
    }
};