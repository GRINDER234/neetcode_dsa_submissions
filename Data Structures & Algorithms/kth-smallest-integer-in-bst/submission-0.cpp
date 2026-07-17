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
    void kthSmallest_helper(TreeNode * root, int &k, int &val){
        if(!root) return;
        

        kthSmallest_helper(root->left, k, val);

        k--;
        if(k == 0){
            val = root->val;
            return;
        }

        kthSmallest_helper(root->right, k, val);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int val = -989;
        kthSmallest_helper(root, k, val);
        return val;
    }
};
