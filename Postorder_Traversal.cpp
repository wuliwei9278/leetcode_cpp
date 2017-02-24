/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        TreeNode *p = root, *prev = NULL;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            TreeNode *node = s.top();
            if (node->right == NULL || prev == node->right) {
                res.push_back(node->val);
                prev = node;
                s.pop();
            } else {
                p = node->right;
            }
        }
        return res;
    }
};