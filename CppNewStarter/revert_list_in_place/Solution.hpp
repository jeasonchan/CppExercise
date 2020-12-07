//
// Created by chenr on 2020/12/7.
//

#ifndef CPPNEWSTARTER_SOLUTION_HPP
#define CPPNEWSTARTER_SOLUTION_HPP


/**
 * 问题描述
 *
 * 反转单链表m到n之间的节点,0<=m<=n<=长度-1
 *
 */

struct Node {
    int value;
    Node *next;

    explicit Node(int node_value) : value(node_value), next(nullptr) {};

    Node(int node_value, Node *next_node) : value(node_value), next(next_node) {};

};

class Solution {
public:
    Node *revert(Node *head) {
        Node *newHead = nullptr;

        //head，旧链表中的当前节点
        while (head) {

            //保存下一个节点的地址
            Node *temp = head->next;

            //逆向，指向新头
            head->next = newHead;

            //更新新头的地址
            newHead = head;

            //更新旧头的地址
            head = temp;
        }

        return newHead;
    }

    Node *revert(int start, int end, Node *head) {}
};


#endif //CPPNEWSTARTER_SOLUTION_HPP
