class Solution {
private:
    void treeToGraph(TreeNode *node, map<int, vector<int>>& graph, int& index, set<int>& leafs) {
        TreeNode *lchild = node->left;
        TreeNode *rchild = node->right;
        node->val = index;

        if (lchild != NULL) {
            index++;
            lchild->val = index;
            
            graph[node->val].push_back(lchild->val);
            graph[lchild->val].push_back(node->val);
            treeToGraph(lchild, graph, index, leafs);
        }
        if (rchild != NULL) {
            index++;
            rchild->val = index;

            graph[node->val].push_back(rchild->val);
            graph[rchild->val].push_back(node->val);
            treeToGraph(rchild, graph, index, leafs);
        }

        if (rchild == NULL && lchild == NULL) {
            leafs.insert(node->val);
        }
    }

public:
    int countPairs(TreeNode* root, int distance) {
        set<int> leafs;
        set<int>::iterator it;
        set<int> visited;
        map<int, vector<int>> graph;

        int ans = 0;
        int index = 1;
        deque<pair<int, int>> dq;

        treeToGraph(root, graph, index, leafs);
        
        for(it=leafs.begin();it != leafs.end();it++) {
            dq.clear();
            visited.clear();
            dq.push_back(make_pair((*it), 0));
            visited.insert((*it));
            while (dq.size() > 0) {
                int curNode = dq.front().first;
                int curDistance = dq.front().second;
                dq.pop_front();

                curDistance++;
                if (curDistance > distance) {
                    break;
                }

                for(int i=0;i<graph[curNode].size();i++) {
                    if (visited.find(graph[curNode][i]) == visited.end()) {
                        if (leafs.find(graph[curNode][i]) != leafs.end()) {
                            ans++;
                        }
                        else {
                            visited.insert(graph[curNode][i]);
                            dq.push_back(make_pair(graph[curNode][i], curDistance));
                        }
                    }
                }
            }
        }

        return ans / 2;
    }
};