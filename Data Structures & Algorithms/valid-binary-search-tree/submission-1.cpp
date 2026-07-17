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
    bool isValidBSThelper(TreeNode * root, long node_min, long node_max){
        if(!root) return true;
        if((root->val <= node_min || root->val >= node_max)) return false;
        return isValidBSThelper(root->left, node_min, root->val) &&
               isValidBSThelper(root->right, root->val, node_max);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBSThelper(root, LONG_MIN, LONG_MAX);

        // if(root->left->val < root->val && root->right->val > root->val){
        //     return isValidBST(root->left) && isValidBST(root->right);
        // }else{
        //     return false;
        // }

        // if(!root->left && root->right) return (root->right->val > root->val && isValidBST(root->right));
        // else if(root->left && !root->right) return (root->left->val < root->val && isValidBST(root->left));
        // else if(root->left && root->right) return (root->left->val < root->val && root->right->val > root->val && isValidBST(root->left) && isValidBST(root->right));
        // else return true;

        // if(!(root->left->val < root->val && root->right->val > root->val)) return false;
        // return 
    }
};
