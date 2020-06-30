/**
 * 2. 两数相加
 * 
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，
 * 并且它们的每个节点只能存储 一位 数字。
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * https://leetcode-cn.com/problems/add-two-numbers/
 * 
 */

/**
 * Definition for singly-linked list.
 */

#include <stdio.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}

    void p() {
        ListNode* guard = this;
        while (nullptr != guard->next) {
            printf("%d -> ", guard->val);
            guard = guard->next;
        }
        printf("%d\n", guard->val);
    }

    ListNode* add(int val) {
        ListNode* n = new ListNode(val);
        this->next = n;
        return this->next;
    }

    // TODO Release
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (nullptr == l1) return l1;
        if (nullptr == l2) return l2;

        int sum = l1->val + l2->val;
        int carry = sum / 10;
        ListNode* res = new ListNode(sum % 10);
        ListNode* next = res;

        l1 = l1->next;
        l2 = l2->next;
        while ((nullptr != l1) && (nullptr != l2)) {
            sum = (l1->val + l2->val + carry);
            next->next = new ListNode(sum % 10);
            carry = sum / 10;

            l1 = l1->next;
            l2 = l2->next;

            next = next->next;
        }

        while (nullptr != l1) {
            sum = (l1->val + carry);
            next->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1->next;

            next = next->next;
        }

        while (nullptr != l2) {
            sum = (l2->val + carry);
            next->next = new ListNode(sum % 10);
            carry = sum / 10;
            l2 = l2->next;

            next = next->next;
        }

        if (carry > 0) {
            next->next = new ListNode(carry);
        }

        return res;
    }
};


int main() {
    Solution solver;

    ListNode* input1 = new ListNode(2);
    input1->add(4)->add(3);

    ListNode* input2 = new ListNode(0);
    // input2->add(6)->add(9);

    printf("Input1: ");
    input1->p();

    printf("Input2: ");
    input2->p();

    ListNode* res = solver.addTwoNumbers(input1, input2);
    printf("Result: ");
    res->p();

}


