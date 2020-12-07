//
// Created by chenr on 2020/12/7.
//

#include <iostream>
#include "./Solution.hpp"


inline void printArgs(int argCount, char *argArray[]) {
    for (int i = 0; i < argCount; ++i) {
        std::cout << "argArray[" << i << "]:" << argArray[i] << std::endl;
    }


}

inline void printNodeList(Node *head) {
    while (head) {
        std::cout << head->value << "->";
        head = head->next;
    }

    std::cout << "Null" << std::endl;
}

int main(int argCount, char *argArray[]) {
    printArgs(argCount, argArray);


    Node *head = new Node(1);
    Node *input = head;

    head->next = new Node(2);
    head = head->next;

    head->next = new Node(3);
    head = head->next;

    head->next = new Node(4);
    head = head->next;


    head->next = new Node(5);
    head = head->next;

    head->next = new Node(6);
    head = head->next;

    head->next = new Node(7);
    head = head->next;

    head->next = new Node(8);

    Solution solution;
    Node *result = solution.revert(input);
    printNodeList(result);

    return 0;
}