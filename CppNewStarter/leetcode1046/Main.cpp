#include <vector>
#include <queue>
#include <algorithm>

namespace leetcode1046 {
    using namespace std;

    class Solution {
    public:
        int lastStoneWeight(vector<int> &stones) {
            auto less = [](int &o1, int &o2) -> bool { return o1 < o2; };

            //其实可以直接用std中仿函数  std::less<int>，此处可以训练用的lambda表达式
            priority_queue<int, vector<int>, decltype(less)> queue(less);

            for_each(stones.begin(), stones.end(), [&queue](int &each) { queue.push(each); });

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


        }
    };

}


int main(int argc, char *argv[]) {

    return 0;
}