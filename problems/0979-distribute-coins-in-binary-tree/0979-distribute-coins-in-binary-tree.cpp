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
    int ans;
private:
    int doDistribute(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int leftVal = doDistribute(node->left);
        int rightVal = doDistribute(node->right);

        ans += abs(leftVal) + abs(rightVal);
        return node->val - 1 + leftVal + rightVal;
    }
public:
    int distributeCoins(TreeNode* root) {
        ans = 0;
        
        doDistribute(root);
        return ans;
    }
};