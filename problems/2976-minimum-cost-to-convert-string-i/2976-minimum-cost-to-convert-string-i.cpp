class Solution {
private:
    void dijkstra(vector<map<char, int>>& path, char start, vector<int>& costs) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        costs.assign(26, INT_MAX);
        costs[start - 'a'] = 0;
        pq.push(make_pair(0, start));
        char viaChar;
        int costToVia;
        map<char, int>::iterator it;
        
        while (!pq.empty()) {
            viaChar = pq.top().second;
            costToVia = pq.top().first;
            pq.pop();
            
            if (costs[viaChar - 'a'] < costToVia) 
                continue;
            for(it = path[viaChar - 'a'].begin();it != path[viaChar - 'a'].end();it++) {
                int cost = costToVia + it->second;
                if (cost < costs[it->first - 'a']) {
                    costs[it->first - 'a'] = cost;
                    pq.push(make_pair(cost, it->first));
                }
            }
        }
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans = 0;
        vector<map<char, int>> changable(26);
        map<char, int>::iterator it;
        vector<vector<int>> minCosts(26);

        for(int i=0;i<original.size();i++) {
            it = changable[original[i] - 'a'].find(changed[i]);
            if (it == changable[original[i] - 'a'].end()) {
                changable[original[i] - 'a'][changed[i]] = cost[i];
            }
            else {
                if (it->second > cost[i]) {
                    it->second = cost[i];
                }
            }
        }
        
        for(int i=0;i<26;i++) {
            dijkstra(changable, i + 'a', minCosts[i]);
        }
        for(int i=0;i<source.length();i++) {
            if (source[i] == target[i])
                continue;
            if (minCosts[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                ans = -1;
                break;
            }
            ans += minCosts[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};