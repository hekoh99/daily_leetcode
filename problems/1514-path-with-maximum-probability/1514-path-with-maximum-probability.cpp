class Solution {
private:
    double dijkstra(int start, int end, int n, vector<vector<pair<double, int>>>& path) {
        priority_queue<pair<double, int>> pq;
        vector<double> probs(n, 0);
        double prob;
        int target;
        
        probs[start] = 1;
        pq.push(make_pair(probs[start], start));
        while (!pq.empty()) {
            prob = pq.top().first;
            target = pq.top().second;
            pq.pop();
            if (prob < probs[target])
                continue;
            for(int i=0;i<path[target].size();i++) {
                double viaProb = prob * path[target][i].first;
                if (viaProb > probs[path[target][i].second]) {
                    probs[path[target][i].second] = viaProb;
                    pq.push(make_pair(viaProb, path[target][i].second));
                }
            }
        }
        return probs[end];
    }

public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        double ans = 0;
        vector<vector<pair<double, int>>> node(n);
        for(int i=0;i<edges.size();i++) {
            node[edges[i][0]].push_back(make_pair(succProb[i], edges[i][1]));
            node[edges[i][1]].push_back(make_pair(succProb[i], edges[i][0]));
        }
        ans = dijkstra(start_node, end_node, n, node);
        return ans;
    }
};