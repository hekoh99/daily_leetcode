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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* tmp = head;
        int count = 0;

        ans.push_back(head);
        while (tmp) {
            count++;
            tmp = tmp->next;
        }
        int size = count / k;
        int left = count % k;
        if (left > 0) {
            size++;
        }

        int index = 0;
        for(int i=0;i<k-1;i++) {
            tmp = ans[i];
            index = 0;
            if (i == left && left != 0) {
                size--;
            }            
            while (tmp && index < size - 1) {
                tmp = tmp->next;
                index++;
            }
            if (tmp != NULL) {
                ans.push_back(tmp->next);
                tmp->next = NULL;
            }
            else {
                ans.push_back(NULL);
            }
        }
        return ans;
    }
};