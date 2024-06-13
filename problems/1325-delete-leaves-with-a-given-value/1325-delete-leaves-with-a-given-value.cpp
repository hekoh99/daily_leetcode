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
    void doDelete(TreeNode *parent, TreeNode *node, bool isLeft, int target) {

        if (node->left != NULL) {
            doDelete(node, node->left, true, target);   
        }

        if (node->right != NULL) {
            doDelete(node, node->right, false, target);
        }
        
        
        if (node->left == NULL && node->right == NULL) {
            if (node->val == target) {
                if (isLeft == true) {
                    parent->left = NULL;
                }
                else {
                    parent->right = NULL;
                }
            }
        }
    }
    
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root->left == NULL && root->right == NULL) {
            if (root->val == target) {
                return NULL;
            }
            else {
                return root;
            }
        }
        if (root->left != NULL) {
            doDelete(root, root->left, true, target);
        }
        if (root->right != NULL) {
            doDelete(root, root->right, false, target);
        }

        if (root->left == NULL && root->right == NULL) {
            if (root->val == target) {
                return NULL;
            }
        }
        
        return root;
    }
};