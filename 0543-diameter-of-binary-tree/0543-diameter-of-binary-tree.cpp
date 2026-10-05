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
    int hight(TreeNode* root){
        if(root == NULL ){
            return 0;

        }
        int lefthig = hight(root->left);
        int righthig = hight(root->right);

        return max(lefthig,righthig) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        int leftdia = diameterOfBinaryTree(root->left);
        int rightdia = diameterOfBinaryTree(root->right);

        int currdia = hight(root->left) + hight(root->right);

        return max(currdia,max (rightdia,leftdia));
    }
};