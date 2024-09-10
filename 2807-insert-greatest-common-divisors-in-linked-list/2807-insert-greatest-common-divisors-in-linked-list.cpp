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
    int getGCD(int a, int b) {
        int tmp;
        while (b != 0) {
            tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *tmp = head;
        ListNode *gcdNode;

        int gcd;
        while (tmp) {
            if (tmp->next == NULL) {
                break;
            }
            gcd = getGCD(tmp->val, tmp->next->val);
            gcdNode = new ListNode(gcd);
            gcdNode->next = tmp->next;
            tmp->next = gcdNode;

            tmp = gcdNode->next;
        }
        return head;
    }
};