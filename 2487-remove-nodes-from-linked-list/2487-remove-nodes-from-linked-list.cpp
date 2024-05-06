class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *newHead = head;
        ListNode* tmp = head;
        int index = 0;
        priority_queue<pair<int, int>> pq;
        while (tmp != NULL) {
            pq.push(make_pair(tmp->val, index));
            index++;
            tmp = tmp->next;
        }
        tmp = head;
        index = 0;
        int index2 = 0;
        while (tmp->next != NULL) {
            if (index2 >= pq.top().second) {
                pq.pop();
            }
            else if (tmp->val < pq.top().first) {
                tmp->val = tmp->next->val;
                tmp->next = tmp->next->next;
                if (index == 0) {
                    newHead = tmp;
                }
                index2++;
            } else {
                index++;
                index2++;
                tmp = tmp->next;
            }
        }
        return newHead;
    }
};