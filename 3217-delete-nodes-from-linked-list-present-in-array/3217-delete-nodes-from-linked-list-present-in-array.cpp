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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *tmp = head;
        ListNode *prev = NULL;
        vector<bool> exists(100001, false);
        for(int i=0;i<nums.size();i++) {
            exists[nums[i]] = true;
        }
        while (tmp != NULL) {
            if (exists[tmp->val] == true) {
                if (prev == NULL) {
                    head = tmp->next;
                    prev = NULL;
                }
                else {
                    prev->next = tmp->next;
                }
            }
            else {
                prev = tmp;
            }
            tmp = tmp->next;
        }
        return head;
    }
};