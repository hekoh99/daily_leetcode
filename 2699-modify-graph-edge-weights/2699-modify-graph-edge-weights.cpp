class Solution {
private:
    long long dijkstra(vector<vector<int>>& edges, int nodeCount, int src, int dest) {
        vector<vector<pair<long long, int>>> path(nodeCount);
        for(int i=0;i<edges.size();i++) {
            if (edges[i][2] != -1) {
                path[edges[i][0]].push_back(make_pair(edges[i][2], edges[i][1]));
                path[edges[i][1]].push_back(make_pair(edges[i][2], edges[i][0]));
            }
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(nodeCount, 2e9);
        long long weight;
        int target;

        dist[src] = 0;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            weight = pq.top().first;
            target = pq.top().second;
            pq.pop();

            if (weight > dist[target]) {
                continue;
            }
            for(int i=0;i<path[target].size();i++) {
                long long viaWeight = weight + path[target][i].first;
                if (viaWeight < dist[path[target][i].second]) {
                    dist[path[target][i].second] = viaWeight;
                    pq.push(make_pair(viaWeight, path[target][i].second));
                }
            }
        }
        return dist[dest];
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<int>> ans;
        long long curMin = dijkstra(edges, n, source, destination);
        if (curMin < target) {
            return ans;
        }
        bool isSame = (curMin == target);
        for(int i=0;i<edges.size();i++) {
            if (edges[i][2] == -1) {
                edges[i][2] = isSame ? 2e9 : 1;
                if (!isSame) {
                    long long newMin = dijkstra(edges, n, source, destination);
                    if (newMin <= target) {
                        isSame = true;
                        edges[i][2] += target - newMin;
                    }
                }
            }
        }
        if (isSame) {
            return edges;
        }
        return ans;
    }
};