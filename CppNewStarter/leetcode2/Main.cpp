//
// Created by chenr on 2020/12/2.
//

#include "Solution.hpp"
#include <vector>
#include <memory>

ListNode *generateFromVector(const std::vector<int> &input) {
    auto it = input.begin();
    ListNode *head = nullptr, *tail = nullptr;

    for (auto each:input) {
        if (!head) {
            tail = head = new ListNode(each);
        } else {
            tail->next = new ListNode(each);
            tail = tail->next;
        }
    }

    return head;

}

int main() {
    Solution solution;
    solution.addTwoNumbers(generateFromVector({2, 4, 3}), generateFromVector({5, 6, 4}));

    return 0;
}