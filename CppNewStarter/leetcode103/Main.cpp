#include <vector>
#include <queue>
#include <deque>
#include <iostream>

namespace leetcode103 {
    using namespace std;

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x, TreeNode *leftNode = nullptr, TreeNode *rightNode = nullptr) : val(x), left(leftNode),
                                                                                       right(rightNode) {}
    };

    class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
            if (!root) {
                return {};
            }

            queue<TreeNode *> treeQueue;
            treeQueue.emplace(root);
            vector<vector<int>> ret;
            bool fromLeftToRight = true;

            while (!treeQueue.empty()) {

                //当前层的节点个数
                int sizeOfCurrentFloor = treeQueue.size();

                //擦，一开始为了避免vector扩容而直接指定了大小，结果后面继续用的push操作……没用索引直接进行赋值……蠢了
                //deque<int> currentFloor(sizeOfCurrentFloor);
                deque<int> currentFloor;

                for (int i = sizeOfCurrentFloor; i >= 1; --i) {
                    auto node = treeQueue.front();

                    if (fromLeftToRight) {
                        currentFloor.emplace_back(node->val);
                    } else {
                        currentFloor.emplace_front(node->val);
                    }

                    cout << node->val << " ";
                    treeQueue.pop();

                    if (node->left) {
                        treeQueue.emplace(node->left);
                    }

                    if (node->right) {
                        treeQueue.emplace(node->right);
                    }


                }

                fromLeftToRight = !fromLeftToRight;
                cout << "finish a floor" << endl;
                ret.emplace_back(vector<int>{currentFloor.cbegin(), currentFloor.cend()});
            }


            return ret;
        }


        /**
         * 使用深度优先重构
         * @param root
         * @return
         */
        vector<vector<int>> zigzagLevelOrder_v2(TreeNode *root) {
            //先复习深度优先的遍历，以中序遍历为例
            print(root);

            return {{}};
        }

    private:
        void print(TreeNode *root) {
            if (!root) {
                return;
            }

            print(root->left);
            cout << root->val << " ";
            print(root->right);

        }

    };

}

int main(int argc, char *argv[]) {
    leetcode103::TreeNode node01(1);
    leetcode103::TreeNode node02(2);
    leetcode103::TreeNode node03(3);
    leetcode103::TreeNode node04(4);
    leetcode103::TreeNode node05(5);
    leetcode103::TreeNode node06(6);
    leetcode103::TreeNode node07(7);
    leetcode103::TreeNode node08(8);

    node01.left = &node02;
    node01.right = &node03;

    node02.left = &node04;
    node02.right = &node05;

    node03.left = &node06;

    node05.left = &node07;
    node05.right = &node08;


    leetcode103::Solution solution;
    auto toPrint = solution.zigzagLevelOrder(&node01);

    std::cout << "================================" << std::endl;

    solution.zigzagLevelOrder_v2(&node01);

    return 0;
}
