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
    TreeNode * build_tree(vector<int>& preorder, int l, int r, vector<int>&inorder, int &preidx, unordered_map<int,int> &mpp){
        if(l > r) return nullptr;
        int root_val = preorder[preidx];
        TreeNode * root = new TreeNode(root_val);
        int mid_idx = mpp[root_val];
        preidx = preidx + 1;
        root->left = build_tree(preorder, l, mid_idx-1, inorder, preidx, mpp);
        root->right = build_tree(preorder, mid_idx+1, r, inorder, preidx, mpp);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        int preidx = 0;
        return build_tree(preorder, 0, inorder.size() - 1, inorder, preidx, mpp);
    }
};
