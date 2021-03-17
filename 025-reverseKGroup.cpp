//
// Created by 11135 on 2021/3/16.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode *reverse(ListNode *a, ListNode *b)
    {
        ListNode *pre, *cur, *next;
        pre = nullptr; cur = a; next = a;
        while (cur != b)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode *a, *b;
        a = b = head;
        for (int i = 0; i < k; i++) {
            if (b == nullptr) return head;
            b = b->next;
        }

        ListNode *new_head = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return new_head;
    }
};
