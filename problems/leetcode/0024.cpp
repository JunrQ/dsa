/**
 * 24. 两两交换链表中的节点
 * 
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 * 
 */


/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* sentry = new ListNode(0);
        sentry->next = head;
        ListNode* p1 = sentry;
        ListNode* p2;
        while (p1->next && p1->next->next) {
            p2 = p1->next;
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1->next->next = p2;
            p1 = p2;
        }
        return sentry->next;
    }
};




