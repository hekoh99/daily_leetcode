class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        priority_queue<pair<int, char>> pq;
        if (a > 0) {
            pq.push({a, 'a'});
        }
        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }
        
        pair<int, char> cur;
        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();

            if (ans.length() < 2) {
                ans += cur.second;
                cur.first--;
            }
            else {
                if (ans[ans.length() - 1] == ans[ans.length() - 2] && ans[ans.length() - 1] == cur.second) {
                    if (!pq.empty()) {
                        pair<int, char> tmp = pq.top();
                        pq.pop();
                        ans += tmp.second;
                        tmp.first--;
                        if (tmp.first > 0)
                            pq.push(tmp);
                    }
                    else {
                        break;
                    }
                }
                else {
                    ans += cur.second;
                    cur.first--;
                }
            }
            if (cur.first > 0) {
                pq.push(cur);
            }
        }
        return ans;
    }
};