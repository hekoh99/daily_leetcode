class Solution {
private:
    int getWaitTime(int target, int changeTime) {
        if ((target / changeTime) % 2 == 0) 
            return 0;
        return changeTime - (target % changeTime);
    }

    int dijkstra (vector<vector<int>>& path, int time, int change) {
        int n = path.size();
        vector<int> times(n, INT_MAX);
        vector<int> secondTimes(n, INT_MAX);
        vector<int> visited(n, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int viaNode;
        int timeToVia;

        times[1] = 0;
        pq.push(make_pair(0, 1));

        while (!pq.empty()) {
            viaNode = pq.top().second;
            timeToVia = pq.top().first;
            pq.pop();

            visited[viaNode]++;
            if (visited[viaNode] == 2 && viaNode == (n - 1))
                break;
            
            timeToVia += getWaitTime(timeToVia, change);
            for(int i=0;i<path[viaNode].size();i++) {
                if (visited[path[viaNode][i]] == 2)
                    continue;
                int viaTime = timeToVia + time;
                if (times[path[viaNode][i]] > viaTime) {
                    secondTimes[path[viaNode][i]] = times[path[viaNode][i]];
                    times[path[viaNode][i]] = viaTime;
                    pq.push(make_pair(viaTime, path[viaNode][i]));
                }
                else if (secondTimes[path[viaNode][i]] > viaTime && times[path[viaNode][i]] < viaTime) {
                    secondTimes[path[viaNode][i]] = viaTime;
                    pq.push(make_pair(viaTime, path[viaNode][i]));
                }
            }
        }
        return secondTimes[n - 1];
    }
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> path(n + 1);
        for(int i=0;i<edges.size();i++) {
            path[edges[i][0]].push_back(edges[i][1]);
            path[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = dijkstra(path, time, change);
        return ans;
    }
};