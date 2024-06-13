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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *retNode = new ListNode();
        ListNode* tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL;
        tmp1 = l1->next;
        tmp2 = l2->next;
        int sum = l1->val + l2->val;
        int quo = sum / 10;
        int remain = sum % 10;

        retNode->val = remain;
        ListNode *last = retNode;

        while (tmp1 != NULL && tmp2 != NULL) {
            ListNode *nxt = new ListNode();

            sum = tmp1->val + tmp2->val + quo;
            quo = sum / 10;
            remain = sum % 10;

            nxt->val = remain;
            last->next = nxt;
            last = last->next;


            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        if (tmp1 == NULL) {
            tmp3 = tmp2;
        }
        if (tmp2 == NULL) {
            tmp3 = tmp1;
        }
        while (tmp3 != NULL) {
            sum = quo + tmp3->val;
            quo = sum / 10;
            remain = sum % 10;
            ListNode *nxt = new ListNode();

            nxt->val = remain;
            last->next = nxt;
            last = last->next;
            tmp3 = tmp3->next;
        }

        if (quo != 0) {
            ListNode *nxt = new ListNode();

            nxt->val = quo;
            last->next = nxt;
            last = last->next;
        }

        return retNode;
    }
};