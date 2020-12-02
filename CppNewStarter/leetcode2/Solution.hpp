//
// Created by chenr on 2020/12/2.
//

#ifndef CPPNEWSTARTER_SOLUTION_HPP
#define CPPNEWSTARTER_SOLUTION_HPP


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    /**
     * 1-2-3 + 1-2-3
     *
     * 1-2-3 + 1-2-3-4
     *
     * 9-9-9 + 9-9-9-9-9
     *
     * @param l1
     * @param l2
     * @return
     */
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr, *tail = nullptr;

        //累加进位
        int carry = 0;

        while (l1 || l2) {
            int l1_value = l1 ? l1->val : 0;
            int l2_value = l2 ? l2->val : 0;
            int sum = l1_value + l2_value + carry;
            carry = sum / 10;
            sum = sum - carry * 10;

            if (!head) {
                head = tail = new ListNode(sum);
            } else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }

            if (l1) {
                l1 = l1->next;
            }

            if (l2) {
                l2 = l2->next;
            }

        }

        if (carry > 0) {
            tail->next = new ListNode(carry);
        }

        return head;
    }
};

#endif //CPPNEWSTARTER_SOLUTION_HPP

