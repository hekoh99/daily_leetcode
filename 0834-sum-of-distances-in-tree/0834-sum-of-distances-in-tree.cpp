class Solution {
private:
    void dfs0(int i, int parent, vector<int>& sum, vector<int>& cnt, vector<vector<int>>& tree){
        for(int j: tree[i]){
            if (j==parent) continue;
            dfs0(j, i, sum, cnt, tree);
            cnt[i]+=cnt[j];
            sum[i]+=sum[j]+cnt[j];      //subtree for root=i
        }
    }
    void reroot(int i, int parent, vector<int>& sum, vector<int>& cnt, vector<vector<int>>& tree){
        int n = tree.size();
        for (int j: tree[i]){
            if (j==parent) continue;
            sum[j]=sum[i]+n-2*cnt[j];
            reroot(j, i, sum, cnt, tree);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        // sum[i] : sum of distances in subtree i when root is 0
        // cnt[i] : the number of nodes in subtree i 
        vector<int> sum(n, 0), cnt(n, 1);

        for(int i=0;i<edges.size();i++) {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }

        dfs0(0, -1, sum, cnt, tree);
        reroot(0, -1, sum, cnt, tree);
        return sum;
    }
};