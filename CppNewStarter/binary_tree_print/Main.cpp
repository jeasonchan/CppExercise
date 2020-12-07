//
// Created by chenr on 2020/12/7.
//

#include "./Solution.hpp"

int main() {
    Node *node_01 = new Node(1);
    Node *node_02 = new Node(2);
    Node *node_03 = new Node(3);
    Node *node_04 = new Node(4);
    Node *node_05 = new Node(5);
    Node *node_06 = new Node(6);
    Node *node_07 = new Node(7);


    node_01->left = node_02;
    node_01->right = node_03;

    node_02->left = node_04;

    node_03->left = node_05;
    node_03->right = node_06;

    node_05->left = node_07;

    Solution solution;
    solution.root_between_print(node_01);

    std::cout << std::endl;
    solution.root_before_print(node_01);

    std::cout << std::endl;
    solution.root_after_print(node_01);

    return 0;
}