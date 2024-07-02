class Solution {
private:
    vector<int> alice;
    vector<int> bob;
    int aliceUnions;
    int bobUnions;
private:
    int findParent(int target, vector<int>& graph) {
        if (graph[target] == target)
            return target;
        return findParent(graph[target], graph);
    }

    bool mergeUnion(int parent, int target, vector<int>& graph, int& unions) {
        int union1 = findParent(parent, graph);
        int union2 = findParent(target, graph);
        // 이미 하나로 연결되어 있음
        if (union1 == union2)
            return false;
        graph[union2] = union1;
        unions--;
        return true;
    }

    static bool compare(vector<int>& a, vector<int>& b) {
        return a[0] > b[0];
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int require = 0;
        // union 초기화.
        for(int i=0;i<n + 1;i++) {
            alice.push_back(i);
            bob.push_back(i);
        }
        aliceUnions = n;
        bobUnions = n;
        // type 3번을 가장 먼저 사용할 수 있도록 정렬.
        sort(edges.begin(), edges.end(), compare);
        bool res1, res2 = false;

        for(int i=0;i<edges.size();i++) {
            switch (edges[i][0]) {
                case 1 :
                    if (mergeUnion(edges[i][1], edges[i][2], alice, aliceUnions)) {
                        require++;
                    }
                    break;
                case 2 :
                    if (mergeUnion(edges[i][1], edges[i][2], bob, bobUnions)) {
                        require++;
                    }
                    break;
                case 3 :
                    res1 = mergeUnion(edges[i][1], edges[i][2], alice, aliceUnions);
                    res2 = mergeUnion(edges[i][1], edges[i][2], bob, bobUnions);
                    if (res1 || res2) {
                        require++;
                    }
                    break;
            }
        }

        if (aliceUnions != 1 || bobUnions != 1) {
            return -1;
        }
        return edges.size() - require;
    }
};