/**
 * 61. 旋转链表
 * 
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 
 * https://leetcode-cn.com/problems/rotate-list/
 * 
 */



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* first = head;

        int n = 1;
        while (head->next != nullptr) {
            n++;
            head = head->next;
        }
        ListNode* tail = head;
        ListNode* new_tail = first;
        k = k % n;

        if (k == 0) return first;
        for (int i = 0; i < n - k - 1; ++i) {
            new_tail = new_tail->next;
        }
        ListNode* new_first = new_tail->next;
        new_tail->next = nullptr;

        tail->next = first;
        return new_first;
    }
};
