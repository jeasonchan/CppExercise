#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

namespace leetcode1046 {
    using namespace std;

    class Solution {
    public:
        int lastStoneWeight(vector<int> &stones) {
            auto less = [](int &o1, int &o2) -> bool { return o1 < o2; };

            //其实可以直接用std中仿函数  std::less<int>，此处可以训练用的lambda表达式
            priority_queue<int, vector<int>, decltype(less)> queue(less);

            for_each(stones.begin(), stones.end(), [&queue](int &each) { queue.push(each); });


            //一开始我还想直接用vector,消失的石头直接用0代替，
            //但是，这样就有性能问题，每次的排序时还要对0排序，有点没有必要
            //改用大根堆之后，每次排序的元素个数都在逐渐减少
            while (queue.size() >= 2) {
                int first_top = queue.top();
                queue.pop();

                int second_top = queue.top();
                queue.pop();

                if (first_top != second_top) {
                    queue.push(abs(first_top - second_top));
                }

            }

            return queue.empty() ? 0 : queue.top();
        }


        /**
         * 尝试使用递归实现
         *
         * @param stones
         * @return
         */
        int lastStoneWeight_v2(vector<int> &stones) {
            if (stones.size() > 1) {

                //std:sort 的第三个入参是一个对象，而上面的优先队列的第三个模板是一个typename，因此，再初始化queue实例时，还是使用了一个对象作为入参
                std::sort(stones.begin(), stones.end(), less<int>());

                int first = stones.back();
                stones.pop_back();

                int second = stones.back();
                stones.pop_back();

                if (first != second) {
                    stones.emplace_back(abs(first - second));
                }

                vector<int> newStone{stones.begin(), stones.end()};

                return lastStoneWeight_v2(newStone);
            }

            return stones.empty() ? 0 : stones[1];

        }
    };

}


int main(int argc, char *argv[]) {
    leetcode1046::Solution solution;

    std::vector<int> input{2, 7, 4, 1, 8, 1};

    std::cout << solution.lastStoneWeight_v2(input);

    return 0;
}