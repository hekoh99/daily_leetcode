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
private:
    void setTreeNode(TreeNode *node, int& sum) {
        if (node != NULL) {
            setTreeNode(node->right, sum);
            node->val += sum;
            sum = node->val;
            setTreeNode(node->left, sum);
        }
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        setTreeNode(root, sum);
        
        return root;
    }
};