class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int index) {
        visited[index] = true;
        for(int i=0;i<graph[index].size();i++) {
            if (visited[graph[index][i]] == false) {
                dfs(graph, visited, graph[index][i]);
            }
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        vector<vector<int>> graph(10001, vector<int>());

        for(int i=0;i<stones.size();i++) {
            for(int j=i + 1;j<stones.size();j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<bool> visited(stones.size(), false);
        int unions = 0;
        for(int i=0;i<stones.size();i++) {
            if (visited[i] == false) {
                dfs(graph, visited, i);
                unions++;
            }
        }

        return stones.size() - unions;
    }
};