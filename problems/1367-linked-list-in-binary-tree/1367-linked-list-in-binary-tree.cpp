/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isFound(TreeNode *node, ListNode* target) {
        if (target == NULL) {
            return true;
        }
        if (node == NULL) {
            return false;
        }
        
        if (node->val != target->val) {
            return false;
        }
        return isFound(node->left, target->next) || isFound(node->right, target->next);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        return isFound(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};