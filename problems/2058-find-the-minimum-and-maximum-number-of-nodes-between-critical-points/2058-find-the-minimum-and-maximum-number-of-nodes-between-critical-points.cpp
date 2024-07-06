/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    bool isCriticalPoints(ListNode* cur, ListNode *prev, ListNode *next) {
        if (cur->val < prev->val && cur->val < next->val) {
            return true;
        }
        if (cur->val > prev->val && cur->val > next->val) {
            return true;
        }
        return false;
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *tmp = head;
        ListNode *prev = NULL;
        vector<int> criticalPoints;
        vector<int> ans;

        int index = 0;
        int minDistance = -1;
    
        while (tmp != NULL) {
            if (prev != NULL && tmp->next != NULL) {
                if (isCriticalPoints(tmp, prev, tmp->next)) {
                    if (criticalPoints.size() > 0) {
                        if (minDistance == -1 || minDistance > index - criticalPoints[criticalPoints.size() - 1]) {
                            minDistance = index - criticalPoints[criticalPoints.size() - 1];
                        }
                    }
                    criticalPoints.push_back(index);
                }
            }
            index++;
            prev = tmp;
            tmp = tmp->next;
        }
        if (criticalPoints.size() < 2)
            return {-1, -1};
        ans.push_back(minDistance);
        ans.push_back(criticalPoints[criticalPoints.size() - 1] - criticalPoints[0]);
        return ans;
    }
};