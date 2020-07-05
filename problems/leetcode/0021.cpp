/**
 * 21. 合并两个有序链表
 * 
 * 将两个升序链表合并为一个新的 升序 链表并返回。
 * 新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * 
 */


/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* res = head;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                res->next = l1;
                l1 = l1->next;
            } else {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        if (l1) {
            res->next = l1;
        }
        if (l2) {
            res->next = l2;
        }
        return head->next;
    }
};

