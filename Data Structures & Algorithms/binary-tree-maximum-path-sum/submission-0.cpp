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
    int maxPathSumHelper(TreeNode * root, int &maxsum){
        if(!root) return 0;
        int lmax = max(maxPathSumHelper(root->left, maxsum), 0);
        int rmax = max(maxPathSumHelper(root->right, maxsum), 0);

        maxsum = max(maxsum, lmax + rmax + root->val);
        return root->val + max(lmax,rmax);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxsum = root->val;
        maxPathSumHelper(root, maxsum);
        return maxsum;
    }
};
