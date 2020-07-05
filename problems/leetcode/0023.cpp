/**
 * 23. 合并K个排序链表
 * 
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * 
 */


#include <vector>

using namespace std;


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];

        if (lists.size() == 2) return mergeTwoLists(lists[0], lists[1]);
        
        int mid = lists.size() / 2;
        vector<ListNode* > l1, l2;
        l1.reserve(mid);
        l2.reserve(lists.size() - mid);

        for (int i = 0; i < mid; ++i) {
            l1.push_back(lists[i]);
        }
        for (int i = mid; i < lists.size(); ++i) {
            l2.push_back(lists[i]);
        }
        return mergeTwoLists(mergeKLists(l1), mergeKLists(l2));

    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
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


