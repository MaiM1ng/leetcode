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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if (left == right) return head;
        stack<ListNode*> s;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* p = dummy;
        int cnt = 0;

        while (cnt < left - 1) {
            if (p->next) p = p->next;
            cnt++;
        }

        // 错误
        // ListNode* it = p;
        ListNode* it = p->next;
        cnt = right - left + 1;
        while (cnt) {
            s.push(it);
            cnt--;
            it = it->next;
        }


        while (!s.empty()) {
            ListNode* cur = s.top();
            s.pop();
            p->next = cur;
            p = p->next;
        }
        p->next = it;

        return dummy->next;
    }  
};
