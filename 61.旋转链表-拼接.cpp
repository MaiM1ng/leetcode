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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        if (k == 0) return head;

        int n = 0;
        ListNode* p = head;
        ListNode* tail;
        while (p) {
            n++;
            if (p->next == NULL) tail = p;
            p = p->next;
        }
        k = k % n;
        if (k == 0) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        
        while (fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        fast = slow->next;
        slow->next = NULL;
        tail->next = head;
        head = fast;

        return head;
    }
};
