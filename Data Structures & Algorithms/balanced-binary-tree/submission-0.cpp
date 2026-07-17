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
    int getHeight(TreeNode * root, bool &isbalanced){
        if(!root) return 0;
        int lh = getHeight(root->left, isbalanced);
        int rh = getHeight(root->right, isbalanced);
        if(abs(lh - rh) > 1) isbalanced = false;
        return 1 + max(lh, rh);
    }

public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool isBalanced = true;
        getHeight(root, isBalanced);
        return isBalanced;
    }
};
