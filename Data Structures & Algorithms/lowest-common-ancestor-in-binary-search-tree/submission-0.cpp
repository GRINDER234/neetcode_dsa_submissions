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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * curr = root;
        unordered_set<TreeNode*>st;
        while(curr != p){
            st.insert(curr);
            if(curr->val < p->val){
                curr = curr->right;
            }else if(curr->val > p->val){
                curr = curr->left;
            }
        }

        st.insert(curr);

        curr = root;
        TreeNode * lca;
        while(curr != q){
            auto it = st.find(curr);
            if(it != st.end()) lca = curr;
            if(curr->val < q->val){
                curr = curr->right;
            }else if(curr->val > q->val){
                curr = curr->left;
            }
        }

        auto it = st.find(curr);
        if(it != st.end()) lca = curr;
        return lca; 
    }
};
