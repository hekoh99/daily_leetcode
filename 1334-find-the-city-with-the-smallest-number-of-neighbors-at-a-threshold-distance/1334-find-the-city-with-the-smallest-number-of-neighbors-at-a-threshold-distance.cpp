class Solution {
private:
    void dijkstra(vector<vector<pair<int, int>>>& path, vector<int>& dist, int start) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // <비용, 목적지>
        pq.push(make_pair(0, start));
        dist[start] = 0;

        int cost, viaNode;
        while (!pq.empty()) {
            cost = pq.top().first;
            viaNode = pq.top().second;
            pq.pop();

            if (dist[viaNode] < cost)
                continue;
            for(int i=0;i<path[viaNode].size();i++) {
                int viaCost = cost + path[viaNode][i].first;
                if (viaCost < dist[path[viaNode][i].second]) {
                    dist[path[viaNode][i].second] = viaCost;
                    pq.push(make_pair(viaCost, path[viaNode][i].second));
                }
            }
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> path(n);
        vector<vector<int>> dists(n, vector<int>(n, INT_MAX));

        for(int i=0;i<edges.size();i++) {
            path[edges[i][0]].push_back(make_pair(edges[i][2], edges[i][1]));
            path[edges[i][1]].push_back(make_pair(edges[i][2], edges[i][0]));
        }
        
        for(int i=0;i<n;i++) {
            dijkstra(path, dists[i], i);
        }

        int ans = 0;
        int min = INT_MAX;
        int neighbors = 0;
        for(int i=0;i<n;i++) {
            neighbors = 0;
            for(int j=0;j<dists[i].size();j++) {
                if (dists[i][j] <= distanceThreshold) {
                    neighbors++;
                }
                if (neighbors > min)
                    break;
            }
            if (neighbors <= min) {
                ans = i;
                min = neighbors;
            } 
        }

        return ans;
    }
};