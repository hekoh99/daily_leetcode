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
    bool evaluateTree(TreeNode* root) {
        bool ans;
        switch (root->val) {
            case 0:
                ans = false;
                break;
            case 1:
                ans = true;
                break;
            case 2:
                ans = evaluateTree(root->left) || evaluateTree(root->right);
                break;
            case 3:
                ans = evaluateTree(root->left) && evaluateTree(root->right);
                break;
            default:
                break;
        }
        return ans;
    }
};