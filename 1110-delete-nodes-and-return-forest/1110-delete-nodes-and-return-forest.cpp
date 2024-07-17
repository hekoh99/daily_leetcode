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
    bool findAndDelete(TreeNode *parent, int target, vector<TreeNode *>& ans) {
        TreeNode *lchild = parent->left;
        TreeNode *rchild = parent->right;

        if (lchild != NULL) {
            if (lchild->val == target) {
                if (lchild->left != NULL) {
                    ans.push_back(lchild->left);
                }
                if (lchild->right != NULL) {
                    ans.push_back(lchild->right);
                }
                parent->left = NULL;
                return true;
            }
            else {
                findAndDelete(lchild, target, ans);
            }
        }
        if (rchild != NULL) {
            if (rchild->val == target) {
                if (rchild->left != NULL) {
                    ans.push_back(rchild->left);
                }
                if (rchild->right != NULL) {
                    ans.push_back(rchild->right);
                }
                parent->right = NULL;
                return true;
            }
            else {
                findAndDelete(rchild, target, ans);
            }
        }
        return false;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> ans;
        ans.push_back(root);
        for(int i=0;i<to_delete.size();i++){
            for(int j=0;j<ans.size();j++) {
                if (ans[j]->val == to_delete[i]) {
                    if (ans[j]->left != NULL) {
                        ans.push_back(ans[j]->left);
                    }
                    if (ans[j]->right != NULL) {
                        ans.push_back(ans[j]->right);
                    }
                    ans.erase(ans.begin() + j);
                    continue;
                }
                if (findAndDelete(ans[j], to_delete[i], ans)) {
                    break;
                }
            }
        }
        return ans;
    }
};