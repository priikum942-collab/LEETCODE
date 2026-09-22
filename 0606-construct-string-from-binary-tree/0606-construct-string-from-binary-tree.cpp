/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    string result = "";
    void solve(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        result += to_string(root->val);
        if (root->left) {
            result += "(";
            solve(root->left);
            result += ")";
        }

        if (root->right) {
            if (!root->left) {
                result += "()";
            }
            result += "(";
            solve(root->right);
            result += ")";
        }
    }
    string tree2str(TreeNode* root) {

        solve(root);
        return result;
    }
};