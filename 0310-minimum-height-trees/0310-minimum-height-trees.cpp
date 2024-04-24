class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int> >& edges) {
        vector<list<int> > tree(n);
        deque<int> outerCircle;
        vector<int> ans;
        if (n == 1) return {0};
        if (n == 2) return edges[0];

        for(int i=0;i<edges.size();i++){
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<n;i++) {
            if (tree[i].size() == 1) {  // if it is leaf node
                outerCircle.push_back(i);
            }
        }

        while (n > 2) {
            int curLeafCount = outerCircle.size();
            for(int i=0;i<curLeafCount;i++) {
                int leaf = outerCircle.front();
                int node = tree[leaf].front();
                tree[node].remove(leaf);
                if(tree[node].size() == 1)
                    outerCircle.push_back(node);
                outerCircle.pop_front();
                n--;
            }
        }
        for(int i=0;i<outerCircle.size();i++) {
            ans.push_back(outerCircle[i]);
        }
        return ans;
    }
};