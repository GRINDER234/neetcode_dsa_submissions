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
    int countGoodNodes(TreeNode * root, int maxsoFar){
        if(!root) return 0;

        int res = (root->val >= maxsoFar) ? 1 : 0;
        maxsoFar = max(maxsoFar, root->val);
        res += countGoodNodes(root->left, maxsoFar);
        res += countGoodNodes(root->right, maxsoFar);
        return res;
    }

    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root->val);
    }
};
