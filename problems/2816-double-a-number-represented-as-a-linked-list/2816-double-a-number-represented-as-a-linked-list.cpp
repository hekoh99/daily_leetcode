class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode *tmp = head;
        vector<ListNode *> saved;
        int index = 0;
        while (tmp != NULL) {
            saved.push_back(tmp);
            tmp->val *= 2;
            tmp = tmp->next;
        }
        for(int i=saved.size() - 1; i > 0; i--) {
            saved[i - 1]->val += saved[i]->val / 10;
            saved[i]->val = saved[i]->val % 10;
        }
        if (saved[0]->val >= 10) {
            ListNode *ans = new ListNode();
            ans->val = saved[0]->val / 10;
            saved[0]->val = saved[0]->val % 10;
            ans->next = saved[0];
            return ans;
        }
        else {
            return saved[0];
        }
    }
};