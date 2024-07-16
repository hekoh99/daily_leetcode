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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        vector<TreeNode *> treeInfo(100001, NULL);
        vector<int> parents(100001, 0);
        vector<int> childs(100001, 0);

        int root = 0;
        TreeNode *tmp;
        int parent, child, isLeft;
        
        for(int i=0;i<descriptions.size();i++){
            parent = descriptions[i][0];
            child = descriptions[i][1];
            isLeft = descriptions[i][2];
            
            if (treeInfo[parent] == NULL) {
                treeInfo[parent] = new TreeNode(parent);
            }
            if (treeInfo[child] == NULL) {
                treeInfo[child] = new TreeNode(child);
            }
            
            if (isLeft == 1) {
                treeInfo[parent]->left = treeInfo[child];
            }
            else {
                treeInfo[parent]->right = treeInfo[child];
            }
            parents[parent]++;
            childs[child]++;
        }
        for(int i=0;i<100001;i++) {
            if (parents[i] != 0 && childs[i] == 0)
                root = i;
        }
        return treeInfo[root];
    }
};