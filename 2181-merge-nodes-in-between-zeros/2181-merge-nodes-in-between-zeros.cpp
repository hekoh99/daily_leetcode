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
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = NULL;
        ListNode* prev = ans;
        ListNode *tmp = head;
        int sum = 0;
        while (tmp != NULL) {
            if (tmp->val == 0) {
                if (ans == NULL)
                {
                    ans = new ListNode(sum);
                    prev = ans;
                } else {
                    prev->next = new ListNode(sum);
                    prev = prev->next;
                }
                sum = 0; 
            }
            else {
                sum += tmp->val;
            }
            tmp = tmp->next;
        }
        return ans->next;
    }
};