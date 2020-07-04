/**
 * 19. 删除链表的倒数第N个节点
 * 
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 *   给定一个链表: 1->2->3->4->5, 和 n = 2.
 *   当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 说明：
 *   给定的 n 保证是有效的。
 * 
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;

        for (int i = 0; i < n; ++i) {
            second = second->next;
        }

        if (!second) return head->next;

        while (second->next) {
            second = second->next;
            first = first->next;
        }

        // Release first->next
        // first->next = nullptr;
        first->next = first->next->next;
        return head;
    }
};


