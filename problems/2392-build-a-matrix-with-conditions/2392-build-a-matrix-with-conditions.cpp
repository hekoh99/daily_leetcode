class Solution {
    bool checkValid(vector<set<int>>& orders, int prior, int target, vector<int>& visited) {
        visited[prior] = 1;
        set<int>::iterator it;

        for(it=orders[prior].begin();it != orders[prior].end();it++) {
            if (visited[(*it)] == 0) {
                if ((*it) == target)
                    return false;
                if (checkValid(orders, (*it), target, visited) == false) {
                    return false;
                }
            }
        }
        return true;
    }

    set<int> getOrder(vector<int>& order, vector<set<int>>& graph, int target, vector<int>& visited) {
        set<int> higher;
        set<int> tmp;

        visited[target] = 1;

        set<int>::iterator it;

        for(it=graph[target].begin();it != graph[target].end();it++) {
            if (visited[(*it)] == 0) {
                higher.insert((*it));
                visited[(*it)] = 1;
                tmp = getOrder(order, graph, (*it), visited);
                higher.insert(tmp.begin(), tmp.end());
            }
        }
        return higher;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans;
        vector<int> visited;

        vector<set<int>> rowPrior(k + 1);
        vector<set<int>> colPrior(k + 1);

        for(int i=0;i<rowConditions.size();i++) {
            vector<int> visited(k + 1, 0);
            if (checkValid(rowPrior, rowConditions[i][0], rowConditions[i][1], visited)) 
                rowPrior[rowConditions[i][1]].insert(rowConditions[i][0]);
            else {
                return ans;
            }
        }

        for(int i=0;i<colConditions.size();i++) {
            visited.assign(k + 1, 0);
            if (checkValid(colPrior, colConditions[i][0], colConditions[i][1], visited))
                colPrior[colConditions[i][1]].insert(colConditions[i][0]);
            else {
                return ans;
            }
        }

        ans.assign(k, vector<int>(k, 0));

        vector<int> rowOrder(k + 1, 0);
        vector<int> colOrder(k + 1, 0);

        vector<int> rowStatic(k, 0);
        vector<int> colStatic(k, 0);

        vector<bool> isRowSet(k + 1, false);
        vector<bool> isColSet(k + 1, false);

        int realRow, realCol;
        set<int> tmp;

        for (int i=1;i<=k;i++) {
            if(rowPrior[i].size() == 0) {
                rowOrder[i] = 0;
            }
            else {
                visited.assign(k + 1, 0);
                tmp = getOrder(rowOrder, rowPrior, i, visited);
                rowOrder[i] = tmp.size();
            }
            rowStatic[rowOrder[i]]++;

            if (colPrior[i].size() == 0) {
                colOrder[i] = 0;
            }
            else {
                visited.assign(k + 1, 0);
                tmp = getOrder(colOrder, colPrior, i, visited);
                colOrder[i] = tmp.size();
            }
            colStatic[colOrder[i]]++;
        }

        for(int i=1;i<=k;i++) {
            realRow = 0;
            realCol = 0;

            for(int j=0;j<rowOrder[i];j++) {
                realRow += rowStatic[j];
            }
            realRow = realRow > rowOrder[i] ? realRow : rowOrder[i];
            while (isRowSet[realRow] == true) {
                realRow++;
            }
            
            for(int j=0;j<colOrder[i];j++) {
                realCol += colStatic[j];
            }
            realCol = realCol > colOrder[i] ? realCol : colOrder[i];
            while (isColSet[realCol] == true) {
                realCol++;
            }
            ans[realRow][realCol] = i;
            isRowSet[realRow] = true;
            isColSet[realCol] = true;
        }
        return ans;
    }
};
