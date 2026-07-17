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
    int getHeight(TreeNode * root){
        if(!root) return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTreeHelper(TreeNode * root, int &d){
        if(root == nullptr) return d;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        d = max(d, rh+lh);
        
        diameterOfBinaryTreeHelper(root->left, d);
        diameterOfBinaryTreeHelper(root->right, d);
        return d;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int d = 0;
        return diameterOfBinaryTreeHelper(root, d);
    }
};
