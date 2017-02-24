/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int cur_freq = 0, max_freq = 0;
	TreeNode *pre;
	void inorder(TreeNode *node, vector<int> &res) {
		if (node == NULL) return;
		inorder(node->left, res);
		if (pre != NULL && node->val == pre->val) {
			cur_freq++;
		} else {
			cur_freq = 1;
		}
		if (cur_freq > max_freq) {
			res.erase(res.begin(), res.end());
			res.push_back(node->val);
			max_freq = cur_freq;
		} else if (cur_freq == max_freq) {
			res.push_back(node->val);
		} 
		pre = node;
		inorder(node->right, res);
	}

    vector<int> findMode(TreeNode *root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};



class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        int cur_freq = 0, max_freq = 0;
        TreeNode* pre = NULL;
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            if (pre != NULL && p->val == pre->val) 
                cur_freq++;
            else 
                cur_freq = 1;
            if (cur_freq == max_freq) {
                res.push_back(p->val);
            } else if (cur_freq > max_freq) {
                res.erase(res.begin(), res.end());
                res.push_back(p->val);
                max_freq = cur_freq;
            }
            pre = p;
            p = p->right;
        }
        return res;
    }   
};

// third way to do inorder traversal: Morris Traversal. See http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        TreeNode *cur, *pre;
        cur = root;
        while (cur) {
            if (cur->left == NULL) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right && pre->right != cur) pre = pre->right;
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};