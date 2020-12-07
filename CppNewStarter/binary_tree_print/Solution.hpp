//
// Created by chenr on 2020/12/7.
//
#include <iostream>


#ifndef CPPNEWSTARTER_SOLUTION_HPP
#define CPPNEWSTARTER_SOLUTION_HPP

struct Node {
    int value;
    Node *left;
    Node *right;

    explicit Node(int node_value) : value(node_value), left(nullptr), right(nullptr) {};

    Node(int node_value, Node *left_node, Node *right_node) : value(node_value), left(left_node), right(right_node) {};

};


class Solution {
public:

    /**
     * 中序打印二叉树
     *
     * @param root
     */
    void root_between_print(Node *root) {
        if (!root) {
            return;
        }

        root_between_print(root->left);

        std::cout << root->value << " ";

        root_between_print(root->right);
    }

    void root_before_print(Node *root) {

        if (!root) {
            return;
        }

        std::cout << root->value << " ";
        root_before_print(root->left);
        root_before_print(root->right);

    }

    void root_after_print(Node *root) {
        if (!root) {
            return;
        }

        root_after_print(root->left);
        root_after_print(root->right);
        std::cout << root->value << " ";

    }

};

#endif //CPPNEWSTARTER_SOLUTION_HPP
