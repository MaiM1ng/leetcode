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
    void showl(ListNode* head) {
        ListNode* p = head;
        if (head == NULL) return;
        while(p) {
            printf("%d ", p->val);
            p = p->next;
        }
        printf("\n");
    }

    // 头插法
    ListNode* reverseL(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* pre = NULL;
        ListNode* cur = head;

        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }

    // 递归法
    ListNode* reverseD(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* last = reverseD(head->next);
        head->next->next = head;
        head->next = NULL;

        return last;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        while (head == NULL || head->next == NULL) return head;
        if (left == right) return head;

        int len = right - left + 1;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;
        ListNode* p;
        ListNode* last;
        ListNode* tmp;

        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        p = pre;

        for (int i = 0; i < len; i++) {
            p = p->next;
        }
        last = p->next;
        p->next = NULL;

        tmp = reverseL(pre->next);
        pre->next = tmp;
        while (tmp) {
            tmp = tmp->next;
            if (tmp->next == NULL) break;
        }
        tmp->next = last;

        return dummy->next;
    }  
};
